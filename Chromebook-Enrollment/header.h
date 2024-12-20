#include <Keyboard.h>

// Define Device Version #
#define device_version 124 // Change to the ChromeOS version you expect to use with Centipede

#define ethernet true // Set to false if using wireless setup

#define ssid false      // Define SSID for your wireless connection. Change false to "your ssid"
#define wifi_pass false // Define the password for your wireless connection. Change false to "your wifi-password"
#define username "----" // Define the user name for enrolling the device.
#define password "----" // The password for the enrollment GAFE account.

/* Advanced Network Options */
#define retry 0     // attempt to retry enrollment in the event of an enrollment error;
#define enroll true //[true,false] Set to false for devices which only need WiFi setup

/* Use this section for additional non-traditional methods*/
#define longer_enrollment_time 10 // Set to additional seconds to wait for Device Configuration and Enrollment
#define slowMode 1                // [0,1] Set to 1 if Centipede appears to be moving too quickly at any screen. This will slow down the entire process
#define update_wait_time 10       // Set to seconds to wait for mandatory updates to be downloaded

/* Version Definition */
#define VERSION_124 (device_version >= 124)

/* Character Definition */
#define KEY_LEFT_CTRL 0x80
#define KEY_LEFT_SHIFT 0x81
#define KEY_LEFT_ALT 0x82
#define KEY_RIGHT_CTRL 0x84
#define KEY_RIGHT_SHIFT 0x85
#define KEY_RIGHT_ALT 0x86
#define KEY_UP_ARROW 0xDA
#define KEY_DOWN_ARROW 0xD9
#define KEY_LEFT_ARROW 0xD8
#define KEY_RIGHT_ARROW 0xD7
#define KEY_BACKSPACE 0xB2
#define KEY_TAB 0xB3
#define KEY_ENTER 0xB0
#define KEY_ESC 0xB1
#define KEY_CAPS_LOCK 0xC1
#define KEY_MUTE 0x7F

int buttonPin = 2; // Set a button to any pin
int RXLED = 17;
static uint8_t __clock_prescaler = (CLKPR & (_BV(CLKPS0) | _BV(CLKPS1) | _BV(CLKPS2) | _BV(CLKPS3)));

void bootLoop()
{
    //      digitalWrite(RXLED, LOW);   // set the LED on
    TXLED0;     // TX LED is not tied to a normally controlled pin
    delay(200); // wait for a second
    TXLED1;
    delay(200);
    TXLED0;     // TX LED is not tied to a normally controlled pin
    delay(200); // wait for a second
    TXLED1;
    delay(800);
}

void showSuccess()
{
    digitalWrite(RXLED, HIGH); // set the LED off
    while (true)
    {
        bootLoop();
    }
}

void repeatKey(byte key, int num)
{
    for (int i = 0; i < num; i++)
    {
        Keyboard.write(key);
        delay(1000);
    }
}

void blink()
{
    digitalWrite(RXLED, LOW);
    //  TXLED1;
    delay(250);
    digitalWrite(RXLED, HIGH);
    //  TXLED0;
    delay(250);
}

void wait(int cycles)
{
    for (int i = 0; i < cycles; i++)
    {
        blink();
        if (slowMode)
        {
            delay(250);
        }
    }
}

void chooseSetup()
{
    repeatKey(KEY_TAB, 2);
    wait(2);
    Keyboard.write(KEY_ENTER);
    wait(2);
}

void enterCredentials()
{
    wait(5);
    Keyboard.write(KEY_ESC);
    wait(3);
    Keyboard.print(username);
    wait(3);
    Keyboard.write(KEY_ENTER);
    wait(8);
    Keyboard.print(password);
    wait(3);
    Keyboard.write(KEY_ENTER);
    wait(3);
}

void enterEnrollment()
{
    Keyboard.write(KEY_ENTER);
    wait(5);
}

void mute()
{
    Keyboard.write(KEY_MUTE);
}
