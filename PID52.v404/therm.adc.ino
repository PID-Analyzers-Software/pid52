
void Thermostat() {
  //D13 - Heater On/Off Out
  //D14 - Temp In
  // NOTE: try PWM here someday. or PWM on temp and flow over on jacks other thingie
  pinMode(13, OUTPUT);

  for (int kk = tempin = 0; kk < 200; kk++) tempin += analogRead(14);
  tempin = tempin / 200;
  currtemp = (251 * tempin ) / (2815);

  //FUDGE FIX                         measure in the bottom hole of block so 232 is really 260 (HOLE IS NO LONGER BACK THERE!)
  currtemp = currtemp * 260. / 231.;
  //FUDGE FIX . END OF FUDGEFIX


  sprintf(pbuf, "newtemp= %d\n\rtempin= %d  <%d>\n\rheater=%d\n\r", newtemp, currtemp, tempin, HEATERSTATE);
  Serial.println(tbuf);
  //oled();
  if (currtemp >= newtemp) {
    HEATERSTATE = 0; // heat
    digitalWrite(13, HEATERSTATE);
  }
  else {
    HEATERSTATE = 1; // cool
    digitalWrite(13, HEATERSTATE);
  }
  delay(200);  // for debug was 2000

}

void READadc1115() {
  const int numReadings = 10;
  int readings1[numReadings];
  int readings2[numReadings];
  int readings3[numReadings];

  int readIndex = 0;
  long total1 = 0;
  long total2 = 0;
  long total3 = 0;

  ads.setGain(GAIN_TWOTHIRDS);  // 2/3x gain +/- 6.144V  1 bit = 3mV      0.1875mV (default)

  float adc0, adc1, adc2, adc3;
  delay(30); //settle time
  adc0 = ads.readADC_SingleEnded(0); delay(30);   // this isnt REALLY needed,but it give some time to settle
  //adc1 = ads.readADC_SingleEnded(1); delay(30);
  //  adc2 = ads.readADC_SingleEnded(2); delay(30);
  //  adc3 = ads.readADC_SingleEnded(3); delay(30);



  for (int i = 0; i < numReadings; i++) {
    // subtract the last reading:
    total1 = total1 - readings1[readIndex];
    total2 = total2 - readings2[readIndex];
    total3 = total3 - readings3[readIndex];

    // read from the SENSOR1:

    readings1[readIndex] = ads.readADC_SingleEnded(1);
    readings2[readIndex] = ads.readADC_SingleEnded(2);
    readings3[readIndex] = ads.readADC_SingleEnded(3);

    // add the reading to the total:
    total1 = total1 + readings1[readIndex];
    total2 = total2 + readings2[readIndex];
    total3 = total3 + readings3[readIndex];

    // advance to the next position in the array:
    readIndex = readIndex + 1;

    // if we're at the end of the array...
    if (readIndex >= numReadings) {
      // ...wrap around to the beginning:
      readIndex = 0;
    }
  }

  adc1 = total1 / numReadings;
  adc2 = total2 / numReadings;
  adc3 = total3 / numReadings;
  Serial.printf("adc1: %.2f. adc2: %.2f. adc3: %.2f. \n", adc1, adc2, adc3);

  /////////// sleazy sleazy sleazy bradshaw and bret.....  adc2 is bias is .24 which is 137v .   adc0 is 3.3v power (freindly!)
  /////////// sleazy sleazy sleazy bradshaw and bret.....  adc3 is HV   is .39 which is 375v
  /////////// sleazy sleazy sleazy bradshaw and bret.....  adc1 is sig  is ??  TBD ??

  float a = 0.00128;
  float b = -10.3697;
  signalin = (float)(adc1) * a + b;
  if (adc2 > 100 and adc2 < 500) {
    BIASVOLTAGE = 124.6;
  } else if (adc2 > 500) {
    BIASVOLTAGE = 75;
  } else {
    BIASVOLTAGE = 0;
  }
  if (adc3 > 4000 and adc3 < 6000) {
    HIGHVOLTAGE = -1114;
  } else if (adc3 > 6000) {
    HIGHVOLTAGE = -510;
  } else {
    HIGHVOLTAGE = 0;
  }  //  //signalin = 6.66666 * signalin;

}
