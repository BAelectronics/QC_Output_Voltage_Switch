/* QC Charger Voltage Switcher
*  v1 2020.12.30
*
*  ---> MODE 1 <---
*  
*  Behavior:
*   + button --> increase the Voltage +0,2V
*   - button --> decrease the Voltage -0,2V
*   Both button pressed at the same time --> set 5V
*
*  PlatformIO configuration changed for MicroCore (platformio.ini) :
*    Main frequency 1,2MHz --> board_build.f_cpu = 1200000L
*  Apply fuses: "pio run -e set_fuses -t fuses" command
*
*  Actual used programmer: USBasp
*/


// Includes ----------------------------------------------------------------------
#include <QC3Control.h>

// Constants ---------------------------------------------------------------------
#define plus_button        1
#define minus_button       0
#define prell_time         100

// Variables ---------------------------------------------------------------------
unsigned long prevMillis = 0;
unsigned long actMillis = 0;

// Library setting ---------------------------------------------------------------
QC3Control quickCharge(4, 3);
//                     +  -

// Init --------------------------------------------------------------------------
void setup()
{
    pinMode(minus_button, INPUT);
    pinMode(plus_button, INPUT);
    delay(200);
}

// Main program ------------------------------------------------------------------
void loop()
{
    if (!(digitalRead(plus_button)))
    {
        if ((digitalRead(minus_button)))
        {
            actMillis = millis();
            if (actMillis - prevMillis >= prell_time) quickCharge.incrementVoltage();
            prevMillis = actMillis;
        }
    }

    if (!(digitalRead(minus_button)))
    {
        if ((digitalRead(plus_button)))
        {
            actMillis = millis();
            if (actMillis - prevMillis >= prell_time) quickCharge.decrementVoltage();
            prevMillis = actMillis;
        }
        else
        {
            quickCharge.set5V();
            delay(200);
        }
    }
}
