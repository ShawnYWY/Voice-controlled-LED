# Voice controlled LED
 This project is based on [esp-Skainet](https://github.com/espressif/esp-skainet) which is Espressif's intelligent voice assistant, which currently supports the Wake Word Engine and Speech Commands Recognition.
 
 This project was implemented on [ESP32-LyraT](https://www.espressif.com/en/products/devkits/esp-audio-devkits)
 
 Wake word : "Hi Jeson!"
 
 
## Introduction
  In this project you can control the LED on the board LyraT by saying "Turn on the light." and "Turn off the light". However, with Skainet there are more things you can do.
 
## Preparation
* idf environment
* ESP32-LyraT

 If you haven't set up idf enviroment on your computer, which is the environment for programming on LyraT, you can follow this [tutorial](https://docs.espressif.com/projects/esp-idf/en/v4.2.1/esp32/get-started/index.html) to set up idf. 

## Get Started (Windows)
* Clone Skainet
 
  In your cmd window type : ```git clone --recursive https://github.com/espressif/esp-skainet.git ```
  
* Navigate to a folder and clone this project
 
  For example go to folder <examples> by typing : ```cd esp-skainet/examples```
 
  Then clone this project by typing ```git clone https://github.com/ShawnYWY/Voice-controlled-LED.git```
 
  Navigate to the folder of this project by typing : ```cd Voice-controlled-LED```

* Compiler and flash the project

  Compiler by typing : ```idf.py build```
 
  Flash by typing : ```idf.py -p PORT flash``` where PORT is your ESP32 board’s serial port name
 
  Then you can wake up LyraT by saying "Hi Jeson!" and then say "Turn on the light" to turn on the green LED on the board, or say "Turn off the light" to turn it off. Remember to say the wake word "Hi jeson" every time before saying your command.
 
* Monitor
  
  You can monitor what's going on on your board by typing ```idf.py -p PORT monitor```
