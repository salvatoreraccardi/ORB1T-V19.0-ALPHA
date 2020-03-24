# ORB1T V19.0 ALPHA
**Elevator pitch**

OBJEX V19.0 is designed for those who develop IoT projects. All the sensors and basic parts, no soldering needed.

**What is OBJEX?**

OBJEX is an "startup" maybe (I don't know, it's early to say). 
Currently, it's a set of experimental IoT projects. Every project has a different name, for example, ORB1T.

### What is it?

ORB1T V19.0 is designed for those who develop IoT projects. This development board includes all sensors and base parts, no soldering needed. 
I decided to make ORB1T V19.0 to improve the development of my IoT projects. Usually, I have to use multiple modules creating a tangle of cables.

### Why I made this?

I made ORB1T V19 for my IoT projects because the Arduino UNO and other similar platforms are not ready for IoT applications. 
So in December 2019, I Designed ORB1T V19 in **only 2 weeks**. ORB1T V19 is the perfect solution for your IoT projects because you 
have microcontroller/wifi connection and sensors in a single board.

### IoT with ORB1T V19.0

*Many IoT (All-in-one) development boards do not allow isolating sensors from the circuit.*

With this board, you have easy access to sensors, you can isolate them, you can add another microcontroller.
Remember, this is a prototype/concept. My next goal is to increase the functionality of ORB1T.

ORB1T V19.0 allows you to control individual sensors also using external microcontrollers. I2C bus and power bus can be used freely by the user.

### With ORB1T V19, you don't need

- External shields (Bme280, sensors ecc..)
- Breadboard or similar
- Wires

<br />

> **For example:** You can isolate an sensor from the power/data bus.

<br />

### Database ready to use

- **Firebase** *is perfect for sync app data in milliseconds*
- **Redis** *is an in-memory data structure project implementing a distributed*
- **MySql** *is an open-source relational database management system*

<br />

> **NOTE:** You can use other databases like MongoDB.

<br />

### Features

- **ESP12E** (Microcontroller with WiFi Module)
- **USB-C and microUSB-B**
- **CP2104** (USB-to-UART Bridge Controller)
- **BME280** (Atmospheric pressure, altitude, humidity and temperature)
- **APDS9960** (Proximity, Light, RGB and Gesture Sensor)
- **MPU-6050** (Triple Axis Accelerometer and Gyro)
- **WS2812B** (RGB PIXEL LED)
- **AMS1117-3.3** (Voltage regulator)
- **SMART power/data BUS** (Management of each component - power/data)

<br />

> **NOTE:** This is a prototype so some of these components have been added to test some additional features.  

<br />

### Issues

- **(A)** VLOGIC status for MPU6050
- **(B)** Logic Level Converter for WS2812B (3.3V to 5V)

<br />

> **A:** I added an external bridge 

> **B:** I used an external shield with BSS138

<br />

### The future of this ORB1T?

In the next three months, I will make a new version of ORB1T. For example, I would use a new microcontroller, new sensors and more. 
I will fix some problems of ORB1T V19.0. Does the future belong to ORB1T V20? We'll see!

<br />

## Demonstration videos

[<img src="https://img.youtube.com/vi/vIh-UPjNHHQ/maxresdefault.jpg" width="80%">](https://youtu.be/vIh-UPjNHHQ)


