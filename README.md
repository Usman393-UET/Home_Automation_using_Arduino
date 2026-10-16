# Home_Automation_using_Arduino
Arduino-based home automation system featuring mobile and PC control. Includes an MIT App Inventor app with interactive buttons and voice control via Bluetooth (HC-05), a Python script for laptop-based voice control in VS Code, and Arduino IDE code for relay switching. Complete with all source files for a smart home setup
# Smart Home Automation System

An **Arduino-based home automation ecosystem** featuring dual-control interfaces. The system allows you to toggle up to three active relays using either a custom Android Mobile App via Bluetooth (HC-05) or a standalone Python script via PC serial connection utilizing voice commands.

---

## 📱 App Interface Overview

The custom Android app interface features a direct connectivity status tracker, voice recognition initialization, and full manual button toggles.

* **Bluetooth Dropdown & Status:** Tap the `Bluetooth` picker to connect to your paired HC-05 module (displays `Disconnected` or `Connected`).
* **Voice Assistant Feed:** Shows real-time speech-to-text outputs under `Heard:` and executed tasks under `Action:`.
* **Interactive Control Matrix:** 4 dedicated power toggle buttons configured for direct relay triggers.

---

## 🛠️ Hardware Requirements

* **Microcontroller:** Arduino Uno / Nano / Mega
* **Bluetooth Module:** HC-05 (or HC-06)
* **Relay Module:** 3-Channel or 4-Channel Relay board (Active-LOW triggered)
* **Jumper Wires & Breadboard**

### Pin Mapping

| Component | Arduino Pin | Description |
| :--- | :--- | :--- |
| **HC-05 TX** | Pin 11 (RX) | SoftwareSerial Receive |
| **HC-05 RX** | Pin 10 (TX) | SoftwareSerial Transmit |
| **Relay 1** | Pin 2 | Controls Light 1 |
| **Relay 2** | Pin 3 | Controls Light 2 |
| **Relay 3** | Pin 4 | Controls Light 3 |

---

## 📂 Project Structure

```text
├── Arduino_Code/
│   └── home_automation.ino    # Core Arduino relay logic & serial routines
├── Python_PC_Control/
│   └── pc_voice_control.py    # Desktop voice control assistant (VS Code)
└── Mobile_App/
    └── home_control.apk       # Compiled MIT App Inventor application
```

---

## 🚀 Setup & Installation

### 1. Arduino Firmware Configuration
1. Open `Arduino_Code/home_automation.ino` in the **Arduino IDE**.
2. Connect your Arduino board via USB.
3. Select your correct board type and COM Port.
4. Upload the code.

### 2. Python PC Voice Setup (VS Code)
The PC script listens for your voice commands using your laptop microphone and pushes raw characters across the USB Serial link (`COM3`).

1. Open the project folder inside **VS Code**.
2. Install the necessary Python dependencies via terminal:
   ```bash
   pip install pyttsx3 SpeechRecognition pyserial
   ```
3. Ensure your Arduino is connected to your PC and verify its active port matches the script configuration (`port = 'COM3'`).
4. Run the application:
   ```bash
   python Python_PC_Control/pc_voice_control.py
   ```

### 3. Mobile App Deployment
1. Transfer the `Mobile_App/home_control.apk` file directly onto your Android device.
2. Enable installation from unknown sources in settings and install.
3. Pair your mobile phone with the **HC-05** module inside your phone's system Bluetooth settings (Default PIN is usually `1234` or `0000`).
4. Launch the application, click **Bluetooth** to establish the wireless runtime link.

---

## 🗣️ Voice Command Dictionary

The Python engine responds dynamically to the following English phrases:

* `"on first light"` / `"off first light"` ➡️ Controls Relay 1
* `"on second light"` / `"off second light"` ➡️ Controls Relay 2
* `"on third light"` / `"off third light"` ➡️ Controls Relay 3
* `"on lights"` / `"off lights"` ➡️ Switches all relays simultaneously
* `"offline"` ➡️ Gracefully terminates the laptop voice monitoring program
