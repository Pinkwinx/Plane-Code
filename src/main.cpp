#include <Arduino.h>
#include <Servo.h> 
#include <ezButton.h>

// put function declarations here:
int talon_pin = 3; // create tallon pin as 3
ezButton limitSwitch(7);  // create ezButton object that attach to pin 7;

Servo talon;
int talon_max_forward = 180; 
int talon_max_reverse = 00; 
int talon_stop = 90; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  limitSwitch.setDebounceTime(50); // set debounce time to 50 milliseconds
  talon.attach(talon_pin); //tells the arduino to control this pin like it's a servo/motor

}

void loop() {
  limitSwitch.loop();

  if(limitSwitch.isPressed())
    talon.write(talon_max_forward); //talon motor goes full power one way

  if(limitSwitch.isReleased())
    talon.write(talon_stop); //talon stops
}

// put function definitions here:

/* The 'Servo.h' library allows you to control motors and servos by passing any value between
0 and 180 into the "write" method (talon.write() in this program).
For a motor: 0 is full power in one direction,
180 is full direction in the opposite direction,
90 is stop.
For a servo: 0 is all the way one direction,
180 is all the way in the opposite direction,
90 is the middle.
*/
