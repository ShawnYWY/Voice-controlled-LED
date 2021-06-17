# Voice controlled LED
 This project is based on [esp-Skainet](https://github.com/espressif/esp-skainet) which is Espressif's intelligent voice assistant, which currently supports the Wake Word Engine and Speech Commands Recognition.
 
 This project was implemented on [ESP32-LyraT](https://www.espressif.com/en/products/devkits/esp-audio-devkits)
 
 In this project you can control the LED on the board LyraT by saying "Turn on the light." and "Turn off the light". However, with Skainet there are many more things you can do.
 
## Introduction
 
## Preparation
* idf environment
* ESP32-LyraT

 If you haven't set up idf enviroment on your computer, which is the environment for programming on LyraT, you can follow this [tutorial](https://docs.espressif.com/projects/esp-idf/en/v4.2.1/esp32/get-started/index.html) to set up idf. 

## Get Started (Windows)
* Clone this project
 
  In your cmd window type : ```git clone --recursive https://github.com/ShawnYWY/Voice-controlled-LED.git```
  
* Navigate to folder 
 
  In your cmd window type : ```cd Voice-controlled-LED/esp-skainet/examples/get_started```

* Compiler and flash the project

  In your cmd window type : ```idf.py flash monitor```
  
