# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)

# 项目信息
project (ConfigTest)

# 加入一个配置头文件，用于处理 CMake 对源码的设置
configure_file (
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
  )

option (TEST_CONFIG
    "tets Config" ON)

if(TEST_CONFIG)
#    add_definitions(-DH_TEST_CONFIG)
    add_compile_definitions(H_TEST_CONFIG)
endif (TEST_CONFIG)

# 指定生成目标
add_executable(ConfigTest main.c)