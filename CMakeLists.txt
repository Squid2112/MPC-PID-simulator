cmake_minimum_required(VERSION 3.10)
project(MPC_PID_simulator)

set(CMAKE_CXX_STANDARD 23)

add_executable(MPC_PID_simulator main.cpp simulation.cpp thermal_system.cpp pid_controller.cpp mpc_controller.cpp hybrid_controller.cpp)