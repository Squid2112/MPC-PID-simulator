cmake_minimum_required(VERSION 3.10)
project(MPC_PID_simulator)

set(CMAKE_CXX_STANDARD 23)

add_executable(MPC_PID_simulator
	main.cpp
	simulation.cpp
	PIDController.cpp
	MPCController.cpp
	HybridController.cpp
	ThermalSystem.cpp
	Simulation.cpp
	"IController.h"
	"PIDController.h"
	"PIDController.cpp"
	"MPCController.h"
	"MPCController.cpp"
)