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

#include <memory>
#include "rclcpp/rclcpp.hpp"

class Talker : public rclcpp::Node {
private:
  rclcpp::TimerBase::SharedPtr m_timer;
  size_t m_count;

  void timer_callback() {
    m_count++;
    // 스핀이 노드를 주기적으로 동작시키는 시점 로그 찍기
    RCLCPP_INFO(this->get_logger(), "I am Simple OOP Example, count : %d",
                m_count);
  }

public:
  Talker() : Node("simple_oop_node"), m_count(0) {
    // 생성자 부분에 로그 찍기
    RCLCPP_WARN(this->get_logger(), "Node Constructor");

    m_timer = this->create_wall_timer(std::chrono::milliseconds(500),
                                      std::bind(&Talker::timer_callback, this));
  }

  ~Talker() {
    // 소멸자 부분에 로그 찍기
    // => 노드 셧다운 이후에 찍힘
    // 따라서 여기에 publisher를 넣으면 동작하지 않음 -> 셧다운 이전에 해야함
    RCLCPP_WARN(this->get_logger(), "Node Destructor");
  }
};

int main(int argc, char **argv) {
  rclcpp::init(argc, argv);

  auto talker = std::make_shared<Talker>();
  rclcpp::spin(talker);

  // 스핀이 언제 종료되는지 찍어보기
  RCLCPP_INFO(talker->get_logger(), "==== Spin Done ====");

  rclcpp::shutdown();
  
  //rclcpp이 언제 종료되는지 찍어봄
  std::cout << "==== After Shutdown ====" << std::endl;

  return 0;
}
