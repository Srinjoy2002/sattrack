import serial
import socket
import time

# Configure Arduino's serial port and baud rate
arduino_port = '/dev/ttyACM0'  # Change as per your setup (e.g., COM3 on Windows)
baud_rate = 9600
arduino_serial = serial.Serial(arduino_port, baud_rate)

# Gpredict output host and port
gpredict_host = '127.0.0.1'  # Gpredict's output server address
gpredict_port = 7356  # Gpredict's output port

# Connect to Gpredict output
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as gpredict_socket:
    gpredict_socket.connect((gpredict_host, gpredict_port))

    # Main loop to receive data from Gpredict
    while True:
        data = gpredict_socket.recv(1024).decode('utf-8').strip()
        if not data:
            continue
        
        # Parse the received data
        # Assuming data format: "satellite_name azimuth elevation"
        satellite_name, azimuth, elevation = data.split()
        azimuth = float(azimuth)
        elevation = float(elevation)

        # Send azimuth and elevation data to Arduino
        azimuth_str = f"{azimuth:.2f}"
        elevation_str = f"{elevation:.2f}"
        arduino_serial.write((azimuth_str + ' ' + elevation_str + '\n').encode())
        
        # Wait for a short duration before next iteration
        time.sleep(1)
