//================================================================   C A L I B R A T E    M E M B R A N E
void getUSD() {
  OLDOLDBUTTON = OLDBUTTON = BUTTON = 0;   // make button return fast
  //while (1) {
    getUSD_0();
    if (OLDOLDBUTTON == OLDBUTTON && 0 != BUTTON) {
      Serial.printf("button=%d t=%.1f . sensorV=%d\n", BUTTON, (float)millis() / 1000., sensorV);
      delay(10);
    }
    else if (BUTTON == OLDBUTTON && 0 != BUTTON) {
      Serial.printf("button=%d t=%.1f . sensorV=%d\n", BUTTON, (float)millis() / 1000., sensorV);
      delay(10);
    }
    else {
      //if(0!=BUTTON) Serial.printf("oops t=%.1f . sensorV=%d\n", (float)millis() / 1000., sensorV);
      OLDBUTTON = BUTTON;
    }
    if (0 != BUTTON) {
            // good . Serial.printf("BUTTON = %d . sensorV=%d\t\t", BUTTON,sensorV);
      //break;
    }
    delay(100);
  //}
  Serial.printf("\nBUTTON = %d . sensorV=%d\t\t", BUTTON,sensorV);
}

void getUSD_0() {

#if 0
#define Slow 722
#define Shi  922
#define Ulow 368
#define Uhi  568
#define Dlow 1310
#define Dhi 1510
#endif


  ReadMembrane();
  if (sensorV <= 45) BUTTON = 0;
  if (sensorV >= Slow && sensorV <= Shi) BUTTON = 1;
  if (sensorV >= Ulow && sensorV <= Uhi) BUTTON = 2;
  if (sensorV >= Dlow && sensorV <= Dhi) BUTTON = 3;
  delay(50);


}

void ReadMembrane() {
  for ( int kk = sensorV = 0; kk < 100; kk++) {
    sensorV  += analogRead(15); //memb
    sensorV2 = analogRead(14);//temp
    sensorV3 = analogRead(12);//hv
    sensorV4 = analogRead(2);//bias
    sensorV5 = analogRead(26);//lamp status????
    delay(2);
  }
  sensorV = sensorV / 100;
  sensorV2 = sensorV2 / 100;
  sensorV3 = sensorV3 / 100;
  sensorV4 = sensorV4 / 100;
  sensorV5 = sensorV5 / 100;

  Serial.printf("\t\t# %d    v,v2,v3,v4,v5  %d %d %d %d %d\n\r", counter++, sensorV, sensorV2, sensorV3, sensorV4, sensorV5);
}

void CalibrateMembrane() {   // first check 5 inputs, then 16,13 as outputs // move 15 to other ports check 2


  // on new pid 52 6/21/19 .  S 750-850 .  UP 360-410 .  DOWN 1450-1550 .  // this all measured nicely!


  for (int jj = counter = 0; jj < 10000; jj++) {
    // 0 is weird but reads           // this tests inputs
    for ( int kk = sensorV = 0; kk < 100; kk++) sensorV  += analogRead(15); //memb
    int sensorV2 = analogRead(14);//temp
    int sensorV3 = analogRead(12);//hv
    int sensorV4 = analogRead(2);//bias
    //int sensorV5 = analogRead(26);//lamp status????
    delay(1);

    sprintf(pbuf, " 15= %d 14= %d \n\r 12= %d 2= %d  \n\r            # %d", sensorV / 100, sensorV2, sensorV3, sensorV4, counter++);
    //oledCLEAR();
    display.clear();
    display.flipScreenVertically();
    oled(); delay(200);
  }
#if 0
  Serial.printf(" running code! bradshaw 6/11\n");
  display.clear();
  oled();
  delay(200); //was 500
  int a = analogRead(15);   // the membrane resistor network switch
  delay(5);
  int b = analogRead(15);   // the membrane resistor network switch
  delay(5);
  int c = analogRead(15);   // the membrane resistor network switch
  int sensorValue = (a + b + c) / 3;
  sprintf(pbuf, "%d\n\r%d - %d", sensorValue, sensorValue - 40, sensorValue + 40);
  display.clear();
  oled();
  delay(200); //was 500
  Serial.println(pbuf);
#endif
}


//================================================================   read the   M E M B R A N E   mode
