# CMake 최소 버전 지정
cmake_minimum_required(VERSION 3.15)

# 프로젝트 이름 및 언어 지정
project(MY_CODING_TEST LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 실행 파일 생성
add_executable(MY_CODING_TEST main.cpp)

include_directories(${CMAKE_SOURCE_DIR}/solutions ${CMAKE_SOURCE_DIR}/DataStructure)
