//   shipped .    fonts Arial Plain 10,16,24 . thats it, may be more on internet. don't dare 6/11

/*
   Model PID51B.v2  up .886 select .592 down .467  nothing 0, bret bradshaw new version 12/12/2018
   415.v5ey y= 0.393x + 14.435  tenp correction from bret
   414.V4D  added LED output pin 26, bret added a pull down resistor
   410.v2b  BRET fixes, lamp on off  readings
            temp 10mv/C so 250mv = 25C
            hv     mv/V so 1400  is 1400 v
            bias 10mv/V so 250mv is 25V
   408.v1a  changed 600 to 475 itming;   mv=1000*analogRead(xx)/762,
            changed to 0,1,2 modes
            did hv*1000 biasx100 and temp was reasonable
            wrote temp and lamp when they are changed   407.v1a  all good, speed up, cycle lamp to save lamp/temp
   406.v1a  read startup lamp and temp, oled() display on startup, put in real analogRead(x) values GOOD???
   405.v1a  clean up of READY, display file write
   404.v1a  just pretty up the core, changed the ready mode to go back to temp mode
   401.v1.a fix thermo, added in display notes, thermocouple works great, lets look at heater
   400.v1c menu works great
*/

//================================================================   D O C U M E N T A T I O N

/*
  bret@hnu.comq Here's the requested pins I need for the 51:

  Inputs:
  in(15)-Membrane Switch  (need 6 resistors, not fussy, have to calibrate
                         for whatever you pick)
  in(14)-Temp. Reading: Up to 250 degrees C (2.5V, so I'll cut the signal with a voltage
             divider; is half okay?)
  in(12)-High Voltage Reading: Actual HV is from about 300-1400V depending on
            if the lamp is running; I'll need to cobble together a voltage
            divider that won't explode. It'll be divided by 476, so it'll
            be in range.
  in(2) -Bias Voltage Reading: This is anywhere from about 45-140V depending on
           if the lamp is running; this will be divided by 100, so that should also be in range.


  Outputs:
  out(16) -Lamp Shut-Off: High turns lamp off, Low turns lamp on
  out(13) -Heater Control: High turns heater on, Low turns heater off
  out(26) -Lamp Status: Ground to turn on.  turn on if hv is out of bounds.

            -Bret & Bradshaw  10/5/2018
*/


/*
   run fixtty to chmod 777 /dev/ttyU* and list the ttyU in use
   after upload run fixtty;s0 (or s1) to do picomm to watch the serial display
   if you are using the serial port. dont do a lot of junk except at the very beginnining
   always display the SRCREV
                         Bradshaw @ BuzzardsBay,MA 02532
*/

/*
  This example code is in the public domain.
  http://www.arduino.cc/en/Tutorial/AnalogReadSerial  then scads of mods by     Bradshaw @ BuzzardsBayMA 02532
*/
