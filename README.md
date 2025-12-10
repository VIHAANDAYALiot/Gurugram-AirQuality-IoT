 Pollution Map of Gurugram 

  Project Overview
This is my IoT project that measures air quality** using an MQ135 sensor and displays it on a dashboard.  
it also controls LED that turns ON when air quality is poor.

  Features
- it Uses MQ135 to measure air pollution
- it Sends data to **Blynk**
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
3. The data is sent to an online dashboard via the Blynk.  
4. Users can view air quality and LED status remotely.

 Setup Instructions
1. Upload `arduino-code/mq135_led.ino` to your Arduino.  
2. Connect the circuit   
3. Open Serial Monitor to test readings.  
4. Set up the blynk to view your data online.

 Dashboard Links
-
- Web Dashboard: 

 Future Plans
- i will Display real-time AQI values on a map of Gurugram.
- and it will Collect data from multiple microcontrollers in different city areas.

- ## Circuit + Code


The air quality sensor abd LED circuit is simulated in TinkerCAD using a potentiometer as a replacement for MQ135.  
- LED turns ON when air quality value goes into a harmful range.  
- Serial Monitor shows `Air Quality: XXX` values.

Simulation link: https://www.tinkercad.com/things/iN54VpWd2ns-iot-project?sharecode=3YNupEM8_71GfxhgEo6RgHxCmteemcQMbyrF67H0xng

<img width="1132" height="600" alt="image" src="https://github.com/user-attachments/assets/4cffb763-cf73-4803-88dc-bac9d6a57d6b" />
ARDUINO CODE: <img width="1063" height="692" alt="image" src="https://github.com/user-attachments/assets/cda5b5b4-0b78-429b-9808-82e6e20fcca1" />
<img width="1677" height="616" alt="image" src="https://github.com/user-attachments/assets/eddeee55-a5cf-4a77-964c-a99bdd7e5eed" />

: Placeholder API + Web Dashboard

- `sensor_data.json` simulates sensor readings from different sectors.
- `index.html` reads this JSON and displays:
  - AQI for each sector
  - LED status based on AQI
- LED logic: turns ON if AQI > 250, otherwise OFF.
- Real Blynk use will replace this soon


- made by vihaan dayal for IoT course
