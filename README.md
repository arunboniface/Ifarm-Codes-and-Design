# iFarm – Automated Farming Robot 🌾🤖

iFarm is a smart agricultural robot designed to automate key farming activities such as **precision ploughing**, **seed sowing**, and **irrigation**. Developed as part of a senior design project, this robot integrates **Arduino**, **ESP32**, and **sensor technologies** to enable efficient, scalable, and affordable farm automation.

## 🚀 Features

- Automated **seed sowing** with servo control
- Soil **moisture monitoring** and automated irrigation system
- Remote control and monitoring via **Blynk IoT platform**
- Real-time feedback and control through smartphone interface
- Precision-based actuation using custom firmware and sensor fusion

## 📁 File Descriptions

- `Blynk_code.ino` – Manages wireless communication with the Blynk IoT platform (ESP32-based).
- `20.seed_sowing_robot.ino` – Controls seed dispensing mechanism and integrates motor/servo logic for sowing.

## 🛠️ Hardware Requirements

- ESP32 / Arduino Uno
- Servo motors (for seed dispensing)
- Soil moisture sensor
- DC motors and motor driver (for movement)
- Water pump
- Blynk IoT app (Android/iOS)

## 📲 Blynk Dashboard

Configure the following virtual pins:
- **V0**: Soil moisture status
- **V1**: Water pump control
- **V2**: Manual override for sowing
- **V3**: Battery/voltage indicator (optional)

## 📦 Installation

1. Clone the repo:
   ```bash
   git clone https://github.com/yourusername/ifarm-robot.git
