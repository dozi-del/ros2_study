#!/usr/bin/env python3

import os

from launch import LaunchDescription
from launch.actions import ExecuteProcess, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration

from launch_ros.actions import Node

# this is the function launch  system will look for
def generate_launch_description():
    # 노드 실행 방식
    turtlesim_node = Node(
        # cmd에 입력하던 ros2 run <package> <executable;실행파일명>을 표기해줌
        # cpp의 경우 빌드해서 나온 실행파일을 적어줌
        package='turtlesim',
        executable='turtlesim_node',
        parameters=[],
        arguments=[],
        output="screen", # 로그를 보고싶을때 스크린으로 보여주겠다는 설정
    )

    turtlesim_teleop_node = Node(
        package='turtlesim',
        executable='draw_square',
        parameters=[],
        arguments=[],
        output="screen",
    )

    # create and return launch description object
    return LaunchDescription(
        [
            turtlesim_node,
            turtlesim_teleop_node,
        ]
    )