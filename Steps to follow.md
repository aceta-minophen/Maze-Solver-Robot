# Reference Starting point 
[LSRB Method](https://medium.com/@TowardInfinity/coding-a-line-follower-robot-using-lsrb-and-finding-the-shortest-path-d906ffec71d)

# Turning Logic
The robot will follow along the white line until the IR sensors detect an intersection (a white line perpendicular to the one that the robot has been following). If the sesnor on the left has detected a white line, it implies that the robot will turn towards left, and same with the right direction. If white line is detected on both the sensors, then the robot will proceed according to the LSRB algorithm. 

## Turning Left (example) architecture
- White line is detected on the left (left IR sensor HIGH)
- Robot moves forward till half the wheelbase is in front of the detected line, then both rear motors LOW
- Turning starts: Servo motor turns left (-45deg), left motor LOW, right motor HIGH
- White line again detected by middle sensor (IR left HIGHH)
- Robot keeps turning until the white line lies between both the IR sensors (half of the trackwidth)
- Servo turns right (0deg), both motors LOW, then both motor will be HIGH until the centre IR sensor is HIGH

