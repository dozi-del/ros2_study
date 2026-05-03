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

int main(int argc, char **argv) {
  rclcpp::init(argc, argv);
  // 생성된 노드는 shared_ptr
  auto node = rclcpp::Node::make_shared("simple_loop_node");

  // WallRate & Rate
  // https://qiita.com/NeK/items/bcf518f6dd79f970bb8e
  rclcpp::WallRate rate(2);  // Hz

  // 노드 주기적으로 반복 실행
  while (rclcpp::ok()) {
    RCLCPP_INFO(node->get_logger(), "Simple Loop Node");
    //파이썬의 spin once와 유사
    rclcpp::spin_some(node);
    //time.sleep과 유사; 호출되어 지정한 주기만큼 반복
    rate.sleep();
  }
  //두 종류 timer 
  // rclcpp::wallRate, rclcpp::Rate
  // 

  rclcpp::shutdown();
  return 0;
}
