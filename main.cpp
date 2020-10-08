#include <Joystick.h>

#define rows[] = {2, 3, 4};
#define cols[] = {8, 9, 10, 11, 12};
Joystick_ Joystick;


void setup() {
  for (int i = 0; i < 2; i++) //rows
  {
    for (int i = 0; i < 4; i++) //cols
    {
      pinMode(i, INPUT_PULLUP);
    }
    
  }
  // Initialize Joystick Library
  Joystick.begin();
}

// Constant that maps the phyical pin to the joystick button.
const int pinToButtonMap = 2;

const int matrix[][4] = //matrix to hold the state of the button
{
  {0, 0, 0}, //row 1 buttons
  {0, 0, 0}, //row 2 buttons
  {0, 0, 0}, //row 3 rotary encoder buttons
  {0, 0, 0}, //row 4 rotary encoder left
  {0, 0, 0}  //row 5 rotary encoder right
};

// Last state of the button
int lastButtonState[4] = {0,0,0,0};

void loop() {
// Read pin values in one row

for (size_t i = 0; i < 4; i++)
{
    // Read pin values in one col
    for (int index = 0; index < 4; index++)
  {
    int currentButtonState = !digitalRead(index + pinToButtonMap);
    if (currentButtonState != lastButtonState[index])
    {
      Joystick.setButton(index, currentButtonState);
      lastButtonState[index] = currentButtonState;
    }
  }

}

  delay(50);
}
