// Copyright 2021 Seoul Business Agency Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// [http://www.apache.org/licenses/LICENSE-2.0](http://www.apache.org/licenses/LICENSE-2.0)
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

//std::bind 
// 클래스 내의 함수를 마치 일반 함수처럼 사용할 수 있게됨


#include <memory>
#include "rclcpp/rclcpp.hpp"
// rclcpp::Node를 상속 받음
class Talker : public rclcpp::Node {
private:
// Node를 주기적으로 실행시켜줄 timer
  rclcpp::TimerBase::SharedPtr m_timer;
  size_t m_count;

  // 실질적으로 실행될 함수
  void timer_callback() {
    m_count++;
    // log 출력
    RCLCPP_INFO(this->get_logger(), "I am Simple OOP Example, count : %d",
                m_count);
  }

public:
// 노드 생성 시, 다음과 같이 이름 설정
  Talker() : Node("simple_oop_node") {
    // create_wall_timer 함수에 timer와 실행시킬 함수 전달하면 편리하게 주기적 실행 가능
    // 
    // this->는 굳이 명시하지 않아도 무관
    m_timer = this->create_wall_timer(std::chrono::milliseconds(500), // 0.5초마다
                                      std::bind(&Talker::timer_callback, this)); // timer_callback 실행
                                      // 클래스 내 함수이므로 std::bind 활용
  }
};

int main(int argc, char **argv) {
  rclcpp::init(argc, argv);

  // spin은 노드 내부에 정해진 timer에 따라 노드를 주기적으로 동작, 갱신시켜줌
  rclcpp::spin(std::make_shared<Talker>()); 
  rclcpp::shutdown();
  return 0;
}
