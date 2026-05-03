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

#include "rclcpp/rclcpp.hpp"
// ros2 cpp api인 rclcpp를 include -> 꼭 필요

int main(int argc, char **argv) {
  //rclcpp을 초기화하여 ros2 환경 준비
  rclcpp::init(argc, argv);
  //node의 생성은 다음과 같이 shared_pointer로 구현하는 것이 권장됨
  auto node = rclcpp::Node::make_shared("simple_node"); // make_shared로 노드 생성; 매개변수로 노드 이름
  // 현 예제는 생성된 Node타입을 auto로 추정하고 있지만 
  // 실제론 rclcpp::Node::SharedPtr의 형식을 가짐

  // 로그 출력 라인; info레벨로 내용 출력
  RCLCPP_INFO(node->get_logger(), "Logger Test");

  rclcpp::shutdown();
  // 실질적인 ros2환경 종료
  return 0;
}
