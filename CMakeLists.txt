cmake_minimum_required(VERSION 3.22)
project(DevIncBase)

set(CMAKE_CXX_STANDARD 14)

add_executable(Recruits SprintThree/Recruits/main.cpp)
add_executable(RadicalHeights SprintThree/RadicalHeights/main.cpp)
add_executable(RadicalHeightsDebug SprintThree/RadicalHeights/debug.cpp)
add_executable(TicTac TicTac/main.cpp)
add_executable(CubeGap SprintThree/CubeGap/main.cpp)
add_executable(GameOfLife GameOfLife/main.cpp)
