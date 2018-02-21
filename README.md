# SimonSays
Simon says for the Arduino

Circuit Diagram
---------------
![Circuit Diagram](https://github.com/AlexMainstone/SimonSays/blob/master/diagram.png)

Adding Additional LED's
-----------------------
Simply add an LED and PushButton to the circuit parallel to the others.

Now just add the port of the LED to:
https://github.com/AlexMainstone/SimonSays/blob/c86486420d1a7cde8bc0a157da3426c18a627cc0/Simon_Says.ino#L9
And the port of the PushButton to:
https://github.com/AlexMainstone/SimonSays/blob/c86486420d1a7cde8bc0a157da3426c18a627cc0/Simon_Says.ino#L10


Features
--------
- Extensibility: More LEDs and switches can be added to the circuit and an array in the code. The code is written with a non-specific led amount in mind.
- Simplicity: An easy game to understand, with a simple design
- Multiple levels: The game continues to level 100, this can be changed in code easily by changing the constant variable in the code.
- Failure: The game clearly states failure by flashing all the LEDs
- Makes use of Push Buttons and LEDs
- Modular code

Instructions
------------
- The goal of the game is to copy the sequence of lights.
- Each button corresponds with an LED, the goal of the game is to remember the sequence of lights presented by the arduino and copy it.
- The arduino will display a light, press the button corresponding with that light.
- The computer will then add another light to the sequence, you must then repeat the sequence using the buttons.
- If you fail to enter the sequence correctly, all of the LEDs will light up, meaning that you have failed! The game will then restart.
