 Pollution Map of Gurugram 

  Project Overview
This is my IoT project that measures air quality** using an MQ135 sensor and displays it on a dashboard.  
it also controls LED that turns ON when air quality is poor.

  Features
- it Uses MQ135 to measure air pollution
- it Sends data to **RobotNinja API**
- it Controls an **LED** based on air quality
- and it Displays live data on a dashboard (mobile app + web)

 Hardware Used
- Arduino UNO  
- MQ135 Sensor  
- LED + 220Ω resistor  
- Jumper wires + Breadboard  

 How It Works
1. Arduino reads air quality values from the MQ135 sensor.  
2. If the value crosses a threshold, the LED turns ON.  
3. The data is sent to an online dashboard via the RobotNinja API.  
4. Users can view air quality and LED status remotely.

 Setup Instructions
1. Upload `arduino-code/mq135_led.ino` to your Arduino.  
2. Connect the circuit as shown in the README diagram (coming soon).  
3. Open Serial Monitor to test readings.  
4. Set up the RobotNinja API to view your data online.

 Dashboard Links
- App: Ill make it soon
- Web Dashboard: Soon

 Future Plans
- i will Display real-time AQI values on a map of Gurugram.
- and it will Collect data from multiple microcontrollers in different city areas.

- ## Circuit + Code

The air quality sensor abd LED circuit is simulated in TinkerCAD using a potentiometer as a replacement for MQ135.  
- LED turns ON when air quality value goes into a harmful range.  
- Serial Monitor shows `Air Quality: XXX` values.

Simulation link: https://www.tinkercad.com/things/iN54VpWd2ns-iot-project?sharecode=3YNupEM8_71GfxhgEo6RgHxCmteemcQMbyrF67H0xng

<img width="1132" height="600" alt="image" src="https://github.com/user-attachments/assets/4cffb763-cf73-4803-88dc-bac9d6a57d6b" />


- made by vihaan dayal for IoT course
