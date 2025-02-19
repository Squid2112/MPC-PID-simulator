# MPC-PID Hybrid Simulator

A C++ simulator for hybrid Model Predictive Control (MPC) and Proportional-Integral-Derivative (PID) control. This project demonstrates a cascade control strategy where an MPC block is integrated with a PID controller to simulate and evaluate hybrid control algorithms. The simulator is designed with modular C++ code and uses CMake for cross-platform builds.

---

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Code Structure](#code-structure)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)
- [Contact](#contact)

---

## Overview

The MPC-PID Hybrid Simulator is developed in C++ to study and compare the performance of hybrid control systems that combine the predictive advantages of MPC with the simplicity and robustness of PID controllers. The simulator includes implementations of:
  
- A **PID controller** (in `pid_controller.cpp`/`.h`)
- An **MPC controller** (in `mpc_controller.cpp`/`.h`)
- A **hybrid controller** that fuses both strategies (in `hybrid_controller.cpp`/`.h`)
- A simulation environment (`simulation.cpp`/`.h`)
- A sample process model, exemplified by a thermal system (`thermal_system.cpp`/`.h`)

This modular design makes it easy to experiment with different control parameters, compare closed-loop performance, and extend the simulation to more complex systems.

---

## Features

- **Hybrid Control:** Combines MPC (for supervisory set point optimization) with a PID (for fast regulatory action) in a cascade configuration.
- **Modular C++ Code:** Each controller and simulation component is separated into distinct modules for clarity and extensibility.
- **CMake Build System:** Easily compile on multiple platforms.
- **Simulation Environment:** Includes a thermal system model that can be used to study controller behavior under various scenarios.
- **Educational Value:** Serves as a reference implementation for those looking to understand and develop hybrid MPC-PID control strategies.

---

## Code Structure

- **`main.cpp`**  
  Entry point for the simulator. Initializes the simulation and controllers.
  
- **`mpc_controller.cpp` / `mpc_controller.h`**  
  Implementation of the Model Predictive Controller.
  
- **`pid_controller.cpp` / `pid_controller.h`**  
  Implementation of the PID Controller.
  
- **`hybrid_controller.cpp` / `hybrid_controller.h`**  
  Combines MPC and PID controllers to form the hybrid control strategy.
  
- **`simulation.cpp` / `simulation.h`**  
  Contains the simulation framework which runs the control loop and updates the process model.
  
- **`thermal_system.cpp` / `thermal_system.h`**  
  Implements a sample thermal process model that the controllers regulate.
  
- **`constants.h`**  
  Defines key constants and parameters used across the simulation.

---

## Requirements

- A C++ compiler (e.g., GCC, Clang, or MSVC)
- [CMake](https://cmake.org/) (version 3.10 or later)
- Standard C++ libraries (no external dependencies required)

---

## Installation

Clone the repository and build the project using CMake:

```bash
git clone https://github.com/Squid2112/MPC-PID-simulator.git
cd MPC-PID-simulator
mkdir build && cd build
cmake ..
make
```
This will compile the simulator and create an executable in the build directory.

---

## Usage

After building, run the simulator from the build directory:

```bash
./MPC-PID-simulator
```
The executable runs the simulation of your hybrid MPC-PID control system on the provided process model (e.g., the thermal system). You can adjust simulation parameters and controller settings by editing the source files or modifying the constants defined in **`constants.h`**.

---

## Contributing

Contributions, issues, and feature requests are welcome!
Feel free to check Issues if you want to contribute.

When contributing, please adhere to the repository’s code style and include tests or documentation for new features.

---

## License

This project is licensed under the MIT License. See the LICENSE file for details.

---

## Contact

If you have any questions, please open an issue in this repository or contact the repository owner directly via GitHub.
