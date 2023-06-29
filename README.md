# distance-control-system
Distance control is provided by changing the color of the LEDs. CAN-bus and Arduino Uno was used.

Introduction:
This is a car door distance control system that when the doors are too close the next item (it can be a car or wall) will activate the led system. It will be calculated for each car and the safe distance is about 70 - 90° (30 cm) When it is bigger than this distance led that embedded the car handle will turn green and which means it is safe the open the door now. If it is 70 - 45° (30 cm - 15 cm) led will turn yellow and it means it is still safe but you need to be careful because you can still exit from the car but you cannot open the door fully. But if the distance is smaller than 45° (15 cm), the led will be red and it means it is not safe to open the door. It means it is too close to the next item. And these information send to the driver.

Components:
Arduino Uno is used as microcontroller and CANbus is used a SPI communication system between Arduinos. Transmitter and receiver Arduinos is connected to breadboard. One breadboard has Ultrasonic Distance Sensor and the other has leds.
Arduino Uno x 2 
CANbus mcp2515 module x 2 
Breadboard x2
Leds x 3 
Jumper cables
Ultrasonic distance sensor 
1k Resistors x3

Explaining Block Diagram:
First Arduino was connected to distance sensor and one of the CANbus. Which port was connected is written in the code lines. Then other Arduino was connected to LEDs and the other CANbus.
