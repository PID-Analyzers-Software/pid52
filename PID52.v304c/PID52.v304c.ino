#define SRCREV "PID52.v304c\n\r  07/17/2020 bbl/c\n\r  +run.time.3c"

/*
 * PID52.v242b  bbl 7/12/20
 *     jack requests trigger be gone
 *       in autozerowait, just return
 *       in autozeroit, wait for S to continue when signal is stable
 *       
 *     BRADSHAW get data folder back in, and temp/range stuff
 *                   
 * 
 *  PID52.v240a bbl 10/15/19
 */

 /*
  * 
  * v301a  add in run.time setting for 1-30 minute run, counting down

I noticed that the 52 has a few changes that are needed.

1. The automatic zero checking should be eliminated since this is a stand alone project.  BBL DONE

2. The Bias and HV values should be switched- This is OK when the detector is connected   BBL DONE

3. Bradshaw will be back this afternoon and will work with Jason to complete the changes on the 52.  JAYSON DROPPED OFF THANKS!

4. After changes are made and you push S, then it should go back to the screen where it displays V, ,bias , then V,  Lamp V DONE

5. From that position V display, when you press S it should display Run? press S,  display autozeroing, then go to set T DONE

6. When at T , then ask Autozero? or skip DONE

7. After that it is in the Run mode.  DONE

8. Should we add run time? since this is manual we should and at the end of the run time it goes to the V display

Jack

  */

// unit came back to have the 5v trigger pulse reversed

// the only thing I see left 8/8/19 is the reached temperature not clearing nicely.
// ok, its menu day.
// lets make the menu go down into NEWRUN(), which will be a set of sub FUNCITONS, heat(), autozero(), run()
/* note to future self
      clean up into modules better, make things less global, more modular.  but this is really cool for now        Serial.printf("Button %d menunumber %d  depressed which is ::%s::\n\r",buttNum,menunumber,menuitems[menunumber]);
      Bret did amazing things with the electronics and getting voltages to 0-3 for me to deal with with the 16 bit ads1115
      bradshaw 7/29/19
*/
void RUNmode();

#include "PID52.h"
#include "PID52.Documentation.h"



//================================================================   L O O P   routine
//================================================================   L O O P   routines
//================================================================   L O O P   routines
//================================================================   L O O P   routines
// the loop routine runs over and over again forever:
//            buttNum = 0; menunumber = 0;

void loop() {

  Serial.printf("in loop  buttnum=%d  menunumber=%d\n\r", buttNum, menunumber);
  Thermostat();
  MenuButton();
  delay(1000);
}


#if 1
void RUNmode() {
  Serial.printf("RUNmode STARTING\n\r"); delay(100);
  heat();
  zero();
  runit();
  Serial.printf("RUNmode complete\n\r");
  Serial.printf("RUNmode complete\n\r");
  Serial.printf("RUNmode complete . sitting for 0 secs\n\r");
  //delay(60000);
}

void heat() {
  Serial.printf("heat STARTING\n\r"); delay(100);
  JUSTheat();
  Serial.printf("heat ending\n\r"); delay(100);

}
void zero() {
  Serial.printf("zero STARTING\n\r"); delay(100);
  AUTOZEROmode();
  Serial.printf("zero ending\n\r"); delay(100);
}
void runit() {
  timeremaining=(float)timein;
  Serial.printf("runit STARTING\n\r"); delay(100);
  starttime=millis();
  while ( timeremaining > 0 ) {
    Thermostat();
    if (buttonPushed(15) == 1) {
      display.clear(); display.display(); Serial.printf("\t\tB R O K E\n\n");
      delay(1000);
      break;
    }
    if (buttonPushed(15) == 3) {
      menunumber = 0;
      display.clear(); display.display(); Serial.printf("\t\treturn return return\n\n");
      delay(1000);
      return;
    }
    // REAL DISPLAY

    READadc1115();// is this too often?
    Thermostat();//  is this too often?
    char rangebufdisplay[64];
    char rangeitems[][20] = {"x1", "x10", "x100", "x1000", ""};
    sprintf(signalinbuf, "%.1f", signalin - autozeroVALUE + .02);
    sprintf(temperactual, " T = %d C", currtemp);
    display.clear(); //$$
    int rangein = readFile(SPIFFS, "/range.txt");
    rangebufdisplay[0] = 0;

    //  bbl going to add in runtime to the range display, sleazy, but quick, and less hours and $$$$$ to QA test the code
    runsecs=((millis()-starttime)/1000)%60;
    runmins=(millis()-starttime)/60000;
    
    
    sprintf(rangebufdisplay, "(%.2f)  R=%s", timeremaining,rangeitems[rangein]); // bbl shortened range to inculde runtime
    //sprintf(rangebufdisplay, "Range = %s", rangeitems[rangein]);


    //start countdown after temperature matches.
    //sprintf(temperbuf, "    heating to %d C\n\r                    press S to skip", newtemp);
    //sprintf(temperactual, " T = %d C", currtemp);

    if(abs(newtemp - currtemp)<5){
      timeremaining -= (float)(1./60.); // try dropping a second
    }
    
    if (BIASVOLTAGE < 50. )              // bradshw, bad bradshaw, just swapped these values as a 20 min fix, $$$$ bargain fix, bad bradshaw 7/12/20
      sprintf(HVbuf, "HV *out*", (float)HIGHVOLTAGE);
    else
      sprintf(HVbuf, "HV = %.0f V", (float)HIGHVOLTAGE);
      
    if (HIGHVOLTAGE < 20.)
      sprintf(BIASbuf, "Bias *out*", (float)BIASVOLTAGE);
    else
      sprintf(BIASbuf, "Bias = %.0f V", (float)BIASVOLTAGE);
      
    oledPrettyScreen(HVbuf, BIASbuf, signalinbuf, 24, rangebufdisplay, temperactual);
    if (buttonPushed(15) == 3) {
      menunumber = 0;
      display.clear(); display.display(); Serial.printf("\t\treturn return return\n\n");
      delay(1000);
      return;
    }
    delay(500);

    // REAL DISPLAY
  }
  Serial.printf("runit ending\n\r"); delay(100);
}

#else
//lots of old stuff is in 229a version
#endif
