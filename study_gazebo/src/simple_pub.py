# 비교를 위한 파이썬 코드
import rclpy
from rclpy.node import Node

from geometry_msgs.msg import Twist

class CmdVelPublisher(Node):

    def __init__(self):
        super().__init__("cmd_vel_pub_node")
				# publisher를 생성하는 부분입니다. 하단에 추가 설명이 있습니다.
        self.publisher = self.create_publisher(Twist, "skidbot/cmd_vel", 10)

				# 어느정도의 주기로 publish 할 것인지를 선택합니다.
				# 지금의 경우 0.5초의 간격으로 publish_callback 함수를 반복 실행합니다.
        timer_period = 0.5  # seconds
        self.timer = self.create_timer(timer_period, self.publish_callback)

				# 시작한다는 log를 출력합니다.
        self.get_logger().info(" DriveForward node Started, move forward during 5 seconds \n")
    
    def publish_callback(self):
				# 상단 형식에 맞추어 Twist Message를 채워줍니다.

				# 전방 속도 0.5 / 각속도 1.0 => 원 운동
        twist_msg = Twist()
        twist_msg.linear.x  = 0.5
        twist_msg.angular.z = 1.0
        self.publisher.publish(twist_msg)

    def stop_robot(self):
        stop_msg = Twist()

				# 전방 속도 0.0 / 각속도 0.0 => 정지
        stop_msg.linear.x  = 0.0
        stop_msg.angular.z = 0.0
        self.publisher.publish(stop_msg)

def main(args=None):
    rclpy.init(args=args)

    cmd_vel_publisher = CmdVelPublisher()
		
		# ROS2에서 시간을 다루기 위해 아래와 같은 방식을 사용합니다.
		# 기본적으로 CPU clock을 사용하기 때문에 절대 시간과 정확히 일치한다는 보장은 없습니다.
    start_time = cmd_vel_publisher.get_clock().now().to_msg().sec
    clock_now  = start_time
    time_delta = 0

		# 5초 동안만 실행하기 위한 로직이 추가되었습니다.
    while (clock_now - start_time) < 5:
				# 단 한 번만 spin시키기 위해 spin_once가 사용되었습니다.
        rclpy.spin_once(cmd_vel_publisher)
        clock_now = cmd_vel_publisher.get_clock().now().to_msg().sec

        time_delta = clock_now - start_time
        print(f'{time_delta} seconds passed')

		# 나머지는 이전 예제와 동일합니다.
    cmd_vel_publisher.stop_robot()

    cmd_vel_publisher.get_logger().info('\n==== Stop Publishing ====')
    cmd_vel_publisher.destroy_node()

    rclpy.shutdown()

if __name__ == '__main__':
    main()