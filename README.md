# VeloX-Rescue V1: Wearable Gesture-Control Transmitter 🧤
An advanced, human-machine interface (HMI) tactical glove developed to enable intuitive, real-time gesture control for indoor search-and-rescue drone operations in disaster-compromised environments.
## 🛠️ Integrated Hardware Framework
* **Arduino Nano** (Central Wearable Microcontroller Architecture)
* **MPU6050 Accelerometer & Gyroscope** (High-precision I2C dynamic tilt tracking)
* **Tactile Push-Button** (Hardware-level safety interlock / Dead-man switch)
* **Wireless Transceiver Link** (High-speed Serial/RF data transmission pipeline)
## 🔌 Circuit Simulation & Wiring Proof
![Circuit Diagram](https://i.postimg.cc/mZV5Fqsp/Push-Button-20260719-131546-0000.png)

> 💡 *Note: Component layout optimized for low-latency data streaming and minimal physical footprint on the wearable chassis.*

| Component Module | Component Pin | Arduino Nano Pin | Wiring Connection Notes |
| :--- | :--- | :--- | :--- |
| **MPU6050** | VCC | **5V** | Main Logic Power |
| **MPU6050** | GND | **GND** | System Common Ground |
| **MPU6050** | SCL | **A5** | I2C Serial Clock Line |
| **MPU6050** | SDA | **A4** | I2C Serial Data Line |
| **Safety Button** | Terminal 1a | **D2** | Configured with Internal Pull-Up Resistor |
| **Safety Button** | Terminal 2a | **GND** | Ground Connection for Active-Low Logic |

## 💻 Firmware Automation Logic Summary
* **Low-Level Register Access:** Directly queries the MPU6050 accelerometer registers (`0x3B`) via the Wire protocol to bypass high-level library overhead and latency.
* **Dynamic Range Mapping:** Processes raw data values ranging from -16384 to 16384 and calibrates them into exact structural tilt angles between -90° and 90° for flight control translation.
* **Hardware State Interlock:** Integrates a fail-safe input condition on Pin D2; if the safety button is released, the firmware overrides sensor data and transmits a safe "Hover/Idle" packet (`0,0`) instantly.
* **Serial Telemetry Stream:** Outputs formatted high-frequency string vectors over the hardware serial link for real-time monitoring and wireless link transmission.