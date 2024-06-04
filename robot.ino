#include <ezButton.h>

#define VRX_PIN  A0 // Arduino pin connected to VRX pin
#define VRY_PIN  A1 // Arduino pin connected to VRY pin
#define SW_PIN   6  // Arduino pin connected to SW  pin

#define LEFT_THRESHOLD  400
#define RIGHT_THRESHOLD 800
#define UP_THRESHOLD    400
#define DOWN_THRESHOLD  800

#define COMMAND_NO     0x00
#define COMMAND_LEFT   0x01
#define COMMAND_RIGHT  0x02
#define COMMAND_UP     0x04
#define COMMAND_DOWN   0x08

ezButton button(SW_PIN);

int motor1pin1 = 2;
int motor1pin2 = 3;

int motor2pin1 = 4;
int motor2pin2 = 5;

int xValue = 0 ; // To store value of the X axis
int yValue = 0 ; // To store value of the Y axis
int bValue = 0; // To store value of the button
int command = COMMAND_NO;

void setup() {
  // put your setup code here, to run once:
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);

  button.setDebounceTime(50); // set debounce time to 50 milliseconds

  //(Optional)
  pinMode(9,  OUTPUT); 
  pinMode(10, OUTPUT);
  //(Optional)
  Serial.begin(9600);
}

void loop() {
  button.loop();
  analogWrite(9, 100); //ENA   pin
  analogWrite(10,200); //ENB pin
  
  // read analog X and Y analog values
  xValue = analogRead(VRX_PIN);
  yValue = analogRead(VRY_PIN);
  analogWrite(9, 100); //ENA   pin
  analogWrite(10, 200); //ENB pin

  // converts the analog value to commands
  // reset commands
  command = COMMAND_NO;

  // check left/right commands
  if (xValue < LEFT_THRESHOLD)
    command = command | COMMAND_LEFT;
  else if (xValue > RIGHT_THRESHOLD)
    command = command | COMMAND_RIGHT;

  // check up/down commands
  if (yValue < UP_THRESHOLD)
    command = command | COMMAND_UP;
  else if (yValue > DOWN_THRESHOLD)
    command = command | COMMAND_DOWN;

  // NOTE: AT A TIME, THERE MAY BE NO COMMAND, ONE COMMAND OR TWO COMMANDS
  if (button.isPressed()) {
    Serial.println("The button is pressed");
    stop();
  }
  // print command to serial and process command
  if (command & COMMAND_LEFT) {
    Serial.println("COMMAND LEFT");
    turnLeft();
  }

  if (command & COMMAND_RIGHT) {
    Serial.println("COMMAND RIGHT");
    turnRight();
  }

  if (command & COMMAND_UP) {
    Serial.println("COMMAND UP");
    forward();
  }

  if (command & COMMAND_DOWN) {
    Serial.println("COMMAND DOWN");
    backward();
  }
}
