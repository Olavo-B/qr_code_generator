# QR Code Generator for Arduino ESP32

This project is a QR code generator for Arduino ESP32 microcontroller. It utilizes the ESP32's built-in WiFi capabilities to connect to the internet and retrieve the necessary data for generating the QR code.

Was used the T-Watch 2020 v1 as a development board. The T-Watch 2020 v1 is a smartwatch based on ESP32 microcontroller. It has a 1.54" TFT display, a 240mAh battery, a microphone, a buzzer, and a vibration motor.

## Functionality

- Create a QR code containing the user input data (using the lib https://github.com/yoprogramo/QRcode_ST7789 or https://github.com/ricmoo/QRCode)
- Read a qrcode link and display the data (using the api  https://goqr.me/api/doc/read-qr-code/)

## Dependencies

- ESP32 WiFi library
- QRCode library
- T-Watch 2020 v1
- ESPAsyncWebSrv library

## Usage

1. Connect the ESP32 to the internet.
2. Run the code on the ESP32.
3. The code will generate a QR code containing the necessary data.
4. Display or use the generated QR code as needed.

## Author

Olavo Barros

## Date

01-12-2023

## References

- ESP32 WiFi library: [Link to the library documentation]
- QRCode library: [Link to the library documentation]
- T-Watch 2020 v1: [Documentation](https://t-watch-document-en.readthedocs.io/en/latest/introduction/product/2020.html) and [Github](https://github.com/Xinyuan-LilyGO/TTGO_TWatch_Library)
