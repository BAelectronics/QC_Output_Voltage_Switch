/* QC Charger Voltage Switcher
*  v1 2020.12.30
*
*  ---> MODE 2 <---
*  
*  Behavior:
*   + button --> jump to 9V from 5V or jump to 12V from 9V
*   - button --> jump to 9V from 12V or jump to 5V from 9V
*   One button hold and press the other --> save set Voltage to the EEPROM (next start auto load)
*
*  PlatformIO configuration changed for MicroCore (platformio.ini) :
*    Main frequency 1,2MHz --> board_build.f_cpu = 1200000L
*  Apply fuses: "pio run -e set_fuses -t fuses" command
*
*  Actual used programmer: USBasp
*/


/* !!! Attention !!!
*  At the first programming, we have to rewrite the memory junk where want to store the last set Voltage
*  Instructions:
*  - Remove slashes at the following define before first programming
*  - Upload the code
*  - Add comment slashes again
*  - Upload the code
*  - Ready for use
*/

//#define FIRST_PROGRAMMING


// Includes ----------------------------------------------------------------------
#include <QC3Control.h>
#include <EEPROM.h>

// Constants ---------------------------------------------------------------------
#define plus_button        1
#define minus_button       0
#define prell_time         100

// Variables ---------------------------------------------------------------------
byte state = 0;
byte set = 1;
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
    
    #ifdef FIRST_PROGRAMMING
    EEPROM.write(1, state);
    while(1);  
    #endif                   

    state = EEPROM.read(1);
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
            if (actMillis - prevMillis >= prell_time)
            {
                if (state < 2) 
                {
                    state++;
                    set = 1;
                }
            }
            prevMillis = actMillis;
        }
    }

    if (!(digitalRead(minus_button)))
    {
        if ((digitalRead(plus_button)))
        {
            actMillis = millis();
            if (actMillis - prevMillis >= prell_time) 
            {
                if (state > 0) 
                {
                    state--;
                    set = 1;
                }
            }
            prevMillis = actMillis;
        }
        else
        {
            EEPROM.write(1, state);
            delay(500);
        }
        
    }

    if (set)
    {
        if (state == 0) quickCharge.set5V();
        if (state == 1) quickCharge.set9V();
        if (state == 2) quickCharge.set12V();
        set = 0;
    }
}
