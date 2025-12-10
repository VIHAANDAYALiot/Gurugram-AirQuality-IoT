Pollution Map of Gurugram
Project Overview

This project measures air quality using an MQ135 sensor and displays the values on a dashboard.
It also controls an LED that turns ON when the air quality becomes poor.

Features

Uses MQ135 to measure air pollution

Sends data to Blynk

Controls an LED based on air quality

Displays live data on a dashboard (mobile app + web)

Hardware Used

Arduino UNO

MQ135 Sensor

LED + 220Ω resistor

Jumper wires

Breadboard

How It Works

The Arduino reads air quality values from the MQ135 sensor.

If the value crosses a threshold, the LED turns ON.

The data is sent to an online dashboard using Blynk.

Users can view air quality and LED status remotely.

Setup Instructions

Upload arduino-code/mq135_led.ino to the Arduino board.

Connect the components according to the circuit diagram.

Open the Serial Monitor to check sensor readings.

Set up Blynk to view the data remotely.

Dashboard Links

Web Dashboard (screenshot shown below):
<img width="1522" height="782" alt="image" src="https://github.com/user-attachments/assets/980ea29f-be8d-4be9-9466-4e401c0e29ec" />

Note: A public live dashboard for external users is not available yet.

Future Plans

Display real-time AQI values on a map of Gurugram.

Collect data from multiple microcontrollers installed in different sectors of the city.

Circuit and Code

The air quality sensor and LED circuit is simulated in TinkerCAD using a potentiometer as a replacement for the MQ135 sensor.

The LED turns ON when the air quality value enters a harmful range.

The Serial Monitor shows values in the format Air Quality: XXX.

Simulation link:
https://www.tinkercad.com/things/iN54VpWd2ns-iot-project?sharecode=3YNupEM8_71GfxhgEo6RgHxCmteemcQMbyrF67H0xng

Images:
<img width="1132" height="600" alt="image" src="https://github.com/user-attachments/assets/4cffb763-cf73-4803-88dc-bac9d6a57d6b" />
<img width="1063" height="692" alt="image" src="https://github.com/user-attachments/assets/cda5b5b4-0b78-429b-9808-82e6e20fcca1" />
<img width="1677" height="616" alt="image" src="https://github.com/user-attachments/assets/eddeee55-a5cf-4a77-964c-a99bdd7e5eed" />

Placeholder API and Web Dashboard

sensor_data.json simulates readings from different sectors.

index.html loads this JSON and displays:

AQI for each sector

LED status based on AQI

LED turns ON if AQI > 250, otherwise OFF.

In the future, real Blynk data will replace the placeholder API.

IMAGES
SERIAL MONITOR SHOWING OUTPUT
<img width="1919" height="1130" alt="image" src="https://github.com/user-attachments/assets/dbdc1075-816e-4071-88b9-c233efb8949d" />
IMAGE OF CIRCUIT
<img width="882" height="757" alt="image" src="https://github.com/user-attachments/assets/ea42d7c7-ae58-492d-b8cd-c8ae9da71c2d" />



Made by Vihaan Dayal for the IoT course.
