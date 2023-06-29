// COOL test routines
// COOL test routines
// COOL test routines
// COOL test routines

#if 0 //  this seems to work well, as expected, waits for 2 or 3, 1 jumps out, for up down controls  TEST WAITING BUTTON
  while (1) {
    int testRBAW = 0; int count=0;
    while (1 != testRBAW) {
      buttNum=0;  // clear button before call
      // lets do button waiting
      Serial.printf("int ReadButtonAgainWaiting() = %d   # %d\n\n", testRBAW = ReadButtonAgainWaiting(),count++);
      delay(500); // wait a bit
    }
    Serial.printf("OUT OF ReadButtonAgainWaiting()\n\n"); delay(5000);
  }
#endif

#if 0   // display menu stuff
  display.clear();
  sprintf(pbuf, "%s",  menuitems[menunumber]);
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_24);
  oledFONTnoclear();
  display.display();
#endif

#if 0 // test the range stuff

  while ( 1 ) {
    for (int kk = 0; kk < 4; kk++) {
      Serial.println(" . TESTING THE RANGE STUFF ");
      //Serial.println(" . TESTING THE RANGE STUFF ");
      //Serial.println(" . TESTING THE RANGE STUFF ");
      //Serial.println(" . TESTING THE RANGE STUFF ");

      writeFile(SPIFFS, "/range.txt", "314");
      delay(4000);
    }

    for (int kk = 0; kk < 10; kk++) {
      Serial.println("\n\n--------------------------------------\n\n");
      rangeval = readFile(SPIFFS, "/range.txt");
      rangebuf();
      Serial.println(rangebufdisplay);
      delay(5000);
      rangeval += 1;
      sprintf(pbuf, "%03d", rangeval);
      writeFile(SPIFFS, "/range.txt", pbuf);
      rangebuf();
      Serial.printf("rangeval now = %d, rangebuf=%s\n\r", rangeval, rangebufdisplay);
    }
  }
#endif


// neat routines to stick at the top of setup for testing components
// neat routines to stick at the top of setup for testing components
// neat routines to stick at the top of setup for testing components
// neat routines to stick at the top of setup for testing components
// neat routines to stick at the top of setup for testing components


#if 0 // read the lamp temp range
sprintf(pbuf, " lamp %d temp %d range %d\n", persistantlamp, newtemp, range);
Serial.printf("%s", pbuf);
oled();
delay(60000);
#endif


//////////////////////// . this tests the various screens for spacing fonts and stuff

#if 0
sprintf(pbuf, "lamp = %d\ntemp = %d\nrange = %d\n", persistantlamp, newtemp, range);
display.setFont(ArialMT_Plain_16);
oledFONT();
delay(1500);
delay(60000);
#endif



#if 0
counter = 0;
/////////////////////////////////// . P L A Y .  W I T H .  H E A T E R
while (1) { //   lets play with the heater..


  pinMode(HEATERONOFFPIN, OUTPUT);
#if 0 //just turn heater on
  digitalWrite(HEATERONOFFPIN, HEATERON);
  sprintf(pbuf, "HEATER PIN D13 SET\n TO 1,  3.23v\n");
  Serial.printf("%s\n", pbuf);
  oled();
  delay(600000);
#endif
  float TemperatureD14;
  float VoltageD14;
  int D14;
  int HEATER;
  for (int kk = D14 = 0; kk < HEATERREADS; kk++) D14 += analogRead(14);
  D14 = D14 / HEATERREADS;

  VoltageD14 = ( (float) D14MEASUREDVOLTAGE * D14) / (float) (D14PINREADING);
  TemperatureD14 = (252. * VoltageD14) / D14MEASUREDVOLTAGE;  //35.9 C is fluke readking

  if (TemperatureD14 < SETTEMP)   {
    HEATER = HEATERON; digitalWrite(HEATERONOFFPIN, HEATERON);
  }
  else {
    HEATER = HEATEROFF;
    digitalWrite(HEATERONOFFPIN, HEATEROFF);
  }
  sprintf(pbuf, "heater is %d  D14=%d\n\tD14=%.3f V\n\tT = %.1f C\ncount = %d  %s\n",
          HEATER, D14, VoltageD14, TemperatureD14, counter++, SRCREV);
  Serial.printf("%s", pbuf);
  oled();
  delay(1500);
}
/////////////////////////////////// . P L A Y .  W I T H .  H E A T E R

#endif



#if 0
while ( 1 ) {
  fileVal = 31415;
  range = fileVal;
  persistantlamp = fileVal;
  temp = fileVal;
  Serial.printf("%d %d %d %d fileVal range persistantlamp temp\n", fileVal, range, persistantlamp, temp);

  fileVal = readFile(SPIFFS, "/lamp.txt");  // get previous lamp and temp and range values

  range = fileVal;
  persistantlamp = fileVal;
  temp = fileVal;
  Serial.printf("%d %d %d %d fileVal range persistantlamp temp\n", fileVal, range, persistantlamp, temp);

  fileVal = 31415;
  range = fileVal;
  persistantlamp = fileVal;
  temp = fileVal;
  Serial.printf("%d %d %d %d fileVal range persistantlamp temp\n", fileVal, range, persistantlamp, temp);

  delay(15000);
}
#endif

#if 0
fileVal = 31415;
range = fileVal;
persistantlamp = fileVal;
temp = fileVal;
Serial.printf("%d %d %d %d fileVal range persistantlamp temp\n", fileVal, range, persistantlamp, temp);
Serial.printf("delay 60 sec\n");
delay(60000);
#endif

#if 0 // lets turn the membrane into ultra reliable U S D . up select down
while ( 1 ) {
  getUSD();  // get up select down
  if (BUTTON != 0) {
    Serial.printf("BUTTON = %d\t\t", BUTTON);
    Serial.printf("back at top routine!\n");
    delay(200);
  }
}
#endif


#if 0 // lets turn the membrane into ultra reliable U S D . up select down
while ( 1 ) {
  getUSD();  // get up select down
  if (BUTTON != 0) {
    Serial.printf("BUTTON = %d\t\t", BUTTON);
    Serial.printf("back at top routine!\n");
    delay(200);
  }
}
#endif

#if 0 // test OLEDprettyScrfeen .   // test the screen spacing and messages
Serial.printf("test oledPrettyScreen\n\r");
oledPrettyScreen("HV 350v", "   Bias 134v", " 110.1   ", 24, "range = x100 ",  "T = 251C");
delay(5000);
oledPrettyScreen("Lamp is off", "Bias LOW", "      check lamp", 10, "range = x1     ", " *cooling*");
delay(4000);
oledPrettyScreen("HV 350v", "   Bias 134v", "    waiting for autozero", 10, "range = x1000", "*heating*");
delay(4000);
#endif

//////////////////////// .  all good test routines . // bring in as needed

#if 0 // . these were neat, but didn't use them

void doTeenyHeat() {
  Serial.println("doTeenyHeat()");
  digitalWrite(HEATERONOFFPIN, HEATERON);
  sprintf(pbuf, "doTeenyHeat()"); oled();
  delay(300);
  digitalWrite(HEATERONOFFPIN, HEATEROFF);
  delay(1000);
}

void doBigHeat() {
  Serial.println("doBigHeat()");
  digitalWrite(HEATERONOFFPIN, HEATERON);
  sprintf(pbuf, "doBigHeat()"); oled();
  delay(200);
  digitalWrite(HEATERONOFFPIN, HEATEROFF);
  delay(1000);
}

void doFULLHEAT() {
  Serial.println("doFULLHeat()");
  sprintf(pbuf, "doFULLHeat()"); oled();
  digitalWrite(HEATERONOFFPIN, HEATERON);
  delay(30000);
}
void doNOHEAT() {
  Serial.println("doNOHeat()");
  sprintf(pbuf, "doNOHeat()"); oled();
  digitalWrite(HEATERONOFFPIN, HEATEROFF);
}
#endif


#if 0 // test all the spiffs stuff

while ( 1 ) {
  delay(6000); Serial.println(SRCREV); Serial.println(SRCREV); Serial.println(SRCREV); Serial.println(SRCREV);

  if (!SPIFFS.begin(FORMAT_SPIFFS_IF_FAILED)) {
    Serial.println("SPIFFS Mount Failed");
    return;
  }

  readFile(SPIFFS, "/lamp.txt"); delay(6000);
  readFile(SPIFFS, "/temp.txt"); delay(6000);
  delay(12000);

#if 0
  writeFile(SPIFFS, "/hello.txt", "Hello ");
  writeFile(SPIFFS, "/hello2.txt", "Hello2bradshaw ");
  writeFile(SPIFFS, "/hello3.txt", "Hello3bradshaw ");
  listDir(SPIFFS, "/", 0);
  delay(6000);
  writeFile(SPIFFS, "/hello.txt", "Hello ");
  appendFile(SPIFFS, "/hello.txt", "World!\r\n");
  readFile(SPIFFS, "/hello.txt");
  readFile(SPIFFS, "/hello3.txt"); delay(6000);
  readFile(SPIFFS, "/setup.ino"); delay(6000);
  readFile(SPIFFS, "/lamp.txt"); delay(6000);
  readFile(SPIFFS, "/temp.txt"); delay(6000);
  renameFile(SPIFFS, "/hello.txt", "/foo.txt");
  //readFile(SPIFFS, "/foo.txt");
  deleteFile(SPIFFS, "/foo.txt");
  //testFileIO(SPIFFS, "/test.txt");
  deleteFile(SPIFFS, "/test.txt");
  Serial.println( "Test complete" ); delay(6000);
#endif
}

#endif

#if 0
bool formatted = SPIFFS.format();
if (formatted) {
  Serial.println("\n\nSuccess formatting");
} else {
  Serial.println("\n\nError formatting");
}
#endif




#if 0  // read membrane switch
while (1) {
  CalibrateMembrane();
  delay(200);
}
#endif



#if 0 // test adc1115
while (1) {
  ads.setGain(GAIN_TWOTHIRDS);  // 2/3x gain +/- 6.144V  1 bit = 3mV      0.1875mV (default)

  int16_t adc0, adc1, adc2, adc3;

  adc0 = ads.readADC_SingleEnded(0); delay(20);   // this isnt REALLY needed,but it give some time to settle
  adc1 = ads.readADC_SingleEnded(1); delay(20);
  adc2 = ads.readADC_SingleEnded(2); delay(20);
  adc3 = ads.readADC_SingleEnded(3); delay(20);
  if (adc0 < 40 || adc0 > 64000) adc0 = 0;        //  this isnt REALLY needed, but it pretties up the numbers
  if (adc1 < 40 || adc1 > 64000) adc1 = 0;
  if (adc2 < 40 || adc2 > 64000) adc2 = 0;
  if (adc3 < 40 || adc3 > 64000) adc3 = 0;
  Serial.printf("\n\t\tcount # %d   \n", count++);
  Serial.printf("\nport  volts  raw\n");
  Serial.printf("AIN0: %.2f  %d\n", (float)(adc0)*.0001875, adc0);
  Serial.printf("AIN1: %.2f  %d\n", (float)(adc1)*.0001875, adc1);
  Serial.printf("AIN2: %.2f  %d\n", (float)(adc2)*.0001875, adc2);
  Serial.printf("AIN3: %.2f  %d\n", (float)(adc3)*.0001875, adc3);
  Serial.println(" ");
  sprintf(pbuf, "bradshaw-%s", SRCREV);
  oled();

  delay(2500);
}

#endif

#if 0 // all work 6/14/19 ! yea    // lets test ALL the outputs,18,19,26,35,26 . should blink them all
while (1) {
  pinMode(18, OUTPUT);    pinMode(19, OUTPUT);    pinMode(21, OUTPUT);
  pinMode(25, OUTPUT);    pinMode(26, OUTPUT);
  digitalWrite(18, -state);    digitalWrite(19, -state);    digitalWrite(21, -state);
  digitalWrite(25, -state);    digitalWrite(26, -state);
  state = ~state;
  Serial.print("testing outputs ");
  Serial.println(-state);
  delay(200);
}
#endif

#if 0 // tesgt all INPUTS, make the OUTPUTS high . D27 and D32 both are 1 with 2.48V yea!
// 6/14/19
//            now test the ADS1115 single ended first
while (1) {
  // inputs!!!
  pinMode(27, INPUT);    pinMode(32, INPUT);
  state = -1; // good 1 and -1 are ON
  pinMode(18, OUTPUT);    pinMode(19, OUTPUT);    pinMode(26, OUTPUT);
  pinMode(35, OUTPUT);    pinMode(26, OUTPUT);
  digitalWrite(18, -state);    digitalWrite(19, -state);    digitalWrite(26, -state);
  digitalWrite(35, -state);    digitalWrite(26, -state);
  //Serial.println(-state);
  Serial.printf("digitalRead(D27 lamp) = %d, DigitalRead(D32 Autozero) = %d\n\r",
                digitalRead(27), digitalRead(32));
  delay(200);
}
#endif

#if 0  //bradshaw test
delay(2000);
sprintf(pbuf, "062");
writeFile(SPIFFS, "/temp.txt", pbuf);
sprintf(pbuf, "001");
writeFile(SPIFFS, "/lamp.txt", pbuf);
#endif
