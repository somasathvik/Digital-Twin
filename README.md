## Problem Statement

We aim to provide farmers and householders the comfort of monitoring and managing their Drip Irrigation systems easier even from areas that might be kilometers apart.

## Solution

- We can create a 3D model of the irrigation system in a virtual world using the Unreal engine.
- Using Websockets provided by Amazon web services, we can communicate between the virtual and the real world.
- Input provided in the form of keypress in the virtual model will be sent to the Esp 32 board through the WebSocket.
- Esp 32 board is responsible for controlling different components of the real world such as pump stations and valves.
- Soil moisture can be monitored in our Virtual world which is sent by the IoT device.

## Workflow

![Workflow](https://user-images.githubusercontent.com/114153904/216104262-70e2438f-5b73-4377-b809-7f2d33d4b95c.jpg)
## Unreal Engine

- 3D model of the drip irrigation system represented as per our convenience
- Core idea for this model is to represent 4 states of the system
- We have created 3 Valves in the real world and need to operate them
- With keypresses, we can control the valves
- Red represents no flow of water
- Yellow represents the flow of water from Valve 1 and 3
- Blue represents the flow of water from Vavle 2 and 3
- Green represents the flow of water from all the valves
- Popup on the screen is given when the soil is dry

![image](https://user-images.githubusercontent.com/114153904/217813520-7f150af7-03d8-4bd1-befb-3270e1ea9c7e.png)
## Amazon Web Sockets

- We create the dynamo db tables
- Lamda functions required have been created and added
- Unreal engine is connected to this with the help of our Amazon web sockets link which is even used in the IoT Device


## ESP 32

- With the help of ESP32 the real-world components can be controlled
- The pins of the board are connected to the relays of the valves
- We use Thonny for the operation of the code
- Soil moisture is checked after every few seconds and is sent back to Unreal to display as a popup if the soil gets dry

![Screenshot_20230209_185210](https://user-images.githubusercontent.com/114153904/217825864-dedfb540-9b5f-4faf-aea0-04cb6fb99d62.png)
![Screenshot_20230209_185226](https://user-images.githubusercontent.com/114153904/217825871-9ddbd7a6-624e-4617-984c-6e11ebaea8c1.png)

Author: Sathvik Soma
