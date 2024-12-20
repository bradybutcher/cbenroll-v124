#include <Keyboard.h>
#include "header.h"


/* Function Declarations */
void bootLoop();
void showSuccess();
void repeatKey(byte key, int num);
void blink();
void wait(int cycles);
void chooseSetup();
void enterCredentials();
void enterEnrollment();
void mute();

void setup()
{
    Keyboard.begin();          // Start the keyboard emulator
    pinMode(buttonPin, INPUT); // Set up the debugging pin. If you want to debug the code, use a length of wire to connect pins 2 and GND on the board
    digitalWrite(buttonPin, HIGH);

    pinMode(RXLED, OUTPUT); // Configure the on-board LED
    digitalWrite(RXLED, LOW);
    TXLED1;
}

void loop()
{ // Main Function - workflow is called within loop();
    if (digitalRead(buttonPin) == 1)
    { // Check for debugging. If not debugging, run the program
        wait(5);
        mute();
        enterEnrollment();
        if (ethernet) // For ethernet setup. To disable, change ethernet to false in header
        {
            TXLED1; // Toggle the TX on-board LED
            wait(10);
            chooseSetup();
            enterCredentials();
            if (retry)
            {
                Keyboard.write(KEY_ENTER); // press "Try again"
                wait(2);
                enterCredentials(); // re-enter credentials
                wait(2);
            }
        }
        showSuccess();
    }
    bootLoop();
}