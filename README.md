# Remote Monitoring and Management of Drip Irrigation using Digital Twin Technology

## Problem Statement

We aim to make the process of monitoring and managing the Drip Irrigation system easier even from areas that might be kilometers apart.

## Solution

- We can create a 3D model of the irrigation system in a virtual world using the Unreal engine.
- Using Websockets provided by Amazon web services, we can communicate between the virtual and the real world.
- Input provided in the form of keypress in the virtual model will be sent to the Esp 32 board through the WebSocket.
- Esp 32 board is responsible for controlling different components of the real world such as pump stations and valves.
- Soil moisture can be monitored in our Virtual world which is sent by the IoT device.
