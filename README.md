# Satellite Tracking and Weather Data Processing System

![Project Image](project_image.png) <!-- Add an image if available -->

Welcome to the repository for the Satellite Tracking and Weather Data Processing System. This project integrates Gpredict, WXtoImg, SDR#, and an Arduino-controlled rotor system to track satellites, receive weather data, and process it into useful information.

## Table of Contents

- [Overview](#overview)
- [Components](#components)
- [Setup](#setup)
- [Usage](#usage)
- [Project Structure](#project-structure)
- [Contributing](#contributing)
- [License](#license)

## Overview

The project combines various software and hardware components to achieve satellite tracking and weather data processing. It includes:
- **Gpredict** for real-time satellite tracking and azimuth/elevation data output.
- **WXtoImg** for processing satellite weather data and generating weather images.
- **SDR#** for receiving and demodulating satellite signals using an SDR receiver (e.g., Airspy).
- **Arduino-controlled rotor system** for controlling antenna positioning using two servo motors.
- **Python script** for integrating all components and automating the system.

## Components

- **Hardware**:
    - [Arduino Uno](https://www.arduino.cc/en/Main/ArduinoBoardUno)
    - 2 servo motors (for azimuth and elevation control)
    - SDR receiver (e.g., [Airspy](https://airspy.com/))
    - V-dipole antenna or equivalent
- **Software**:
    - [Gpredict](https://gpredict.oz9aec.net/)
    - [WXtoImg](https://wxtoimgrestored.xyz/)
    - [SDR#](https://airspy.com/download/)
    - [pyserial](https://pypi.org/project/pyserial/) Python library for serial communication

## Setup

To set up the project:

1. **Clone the repository**:
    ```bash
    git clone [repository URL]
    cd [repository name]
    ```

2. **Install required Python libraries**:
    ```bash
    pip install -r requirements.txt
    ```

3. **Install and configure software**:
    - Follow the instructions provided on the official websites to install and configure Gpredict, WXtoImg, and SDR#.
    - Set up the Arduino-controlled rotor system as per the instructions in the project code.

4. **Connect hardware**:
    - Connect the Arduino Uno to your computer via USB.
    - Connect the servo motors to the Arduino.
    - Connect the SDR receiver to your computer and set up the antenna.

## Usage

To run the system:

1. **Start Gpredict**:
    - Configure Gpredict to output data over a network socket or to a file.

2. **Run the Python script**:
    - Execute the Python script to integrate all components and control the rotor system:
        ```bash
        python pythonscript.py
        ```

3. **Monitor**:
    - Monitor the output to ensure the system is tracking satellites accurately and processing weather data.

## Project Structure

- `pythonscript.py`: The main Python script for integrating the system.
- `requirements.txt`: File containing Python library dependencies.
- `arduino_sketch/`: Folder containing the Arduino sketch for controlling the servos.
- `config/`: Folder containing configuration files for the software.

## Contributing

We welcome contributions to this project. Please read our [CONTRIBUTING.md](CONTRIBUTING.md) file for guidelines on how to contribute.

## License

This project is licensed under the [MIT License](LICENSE).

