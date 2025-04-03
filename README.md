This is a simple Arduino program for a DIY radar system using a servo motor, an ultrasonic distance sensor, and an Arduino (or ESP32).

The Arduino rotates the servo from 0° to 180°, taking a distance measurement at each 1° step. The output consists of the servo angle (in degrees) and the measured distance (in centimeters), formatted as:
0,34
1,21
2,23
3,25

The data is printed to the Serial Monitor in a comma-separated format, where the first value represents the angle, and the second value represents the measured distance.
