cmake_minimum_required(VERSION 3.16)
project(2021___Csolver)

set(CMAKE_CXX_STANDARD 14)


add_executable(2021___Csolver src/main.cpp spike/solve_pendulum.cpp src/odeint/RungeKuttaSolver4.cpp src/odeint/RungeKuttaSolver4.h)

