
#Arduino-Based Driver Drowsiness and Alcohol Detection System

🚗 Project Overview

This project is an IoT and Arduino-based Driver Safety System designed to prevent accidents caused by alcohol consumption and driver drowsiness.
It uses sensors to monitor the driver’s condition in real time and ensures safety through alerts and an engine locking mechanism.

This system demonstrates how embedded systems + IoT can be used to solve real-world safety problems, making driving safer for both the driver and passengers.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

##✨ Features

🍺 Alcohol Detection – MQ-3 Sensor detects alcohol levels in breath.

😴 Drowsiness Detection – IR Sensor monitors eye blink patterns.

🔒 Engine Locking System – Relay module disables engine if unsafe conditions are detected.

🔔 Audio-Visual Alerts – Buzzer + LED notify driver of danger.

🛠 Prototype Implementation – Arduino UNO as the microcontroller brain.

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

##🛠 Components Used

Arduino UNO R3 – main microcontroller

MQ-3 Alcohol Sensor – detects alcohol in breath

IR Sensor – detects drowsiness via eye blinks

Relay Module – engine power cutoff

DC Motor – simulated engine

Buzzer + LED – alert system

Breadboard, Jumper Wires, Resistors, Transistors – for circuit setup

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

##🔄 How It Works

The MQ-3 sensor detects alcohol concentration in the driver’s breath.

The IR sensor monitors eye blink activity to check for drowsiness.

If alcohol or drowsiness is detected:

The buzzer + LED are activated.

The relay module cuts off the engine power.

The engine remains locked until the driver is in a safe state.

