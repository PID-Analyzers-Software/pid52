//================================================================   S E T  U P  routines
void rangebuf() {
  int calc = 1;
  int calcval = 1;

  rangeval = readFile(SPIFFS, "/range.txt");
  Serial.printf(" $$$$$$$$$$$$$$ rangeval, set range bigts = %d\n\r", rangeval);
#if 1
  if (rangeval >= 4 || rangeval < 0) {
    rangeval = 0;
    writeFile(SPIFFS, "/range.txt", "000");
    Serial.printf("     range.txt, of %d was farkeled\n\r", rangeval);
  }
  //Serial.printf("rangeval=%d\n\r", rangeval);
#endif
  for (kk = 1, calc = 1, calcval; kk < rangeval + 1; kk++) calcval = calcval * 10;
  delay(500);;
  //Serial.printf("rangeval=%d . calc = %d\n", rangeval,calcval);
  sprintf(rangebufdisplay, "   = x%d", calcval);

  // set up the range output bits
  pinMode(19, OUTPUT);   
  pinMode(26, OUTPUT);   
  pinMode(25, OUTPUT);

  Serial.printf("\n\n\n      rangeval=%d\n\n", rangeval);
  if (rangeval == 0){
    digitalWrite(19, HIGH);  
    digitalWrite(26, LOW);  
    digitalWrite(25, LOW);
    Serial.println("zw. pin 19");
  }
  if (rangeval == 1){
    digitalWrite(19, LOW);  
    digitalWrite(26, HIGH);  
    digitalWrite(25, LOW); 
    Serial.println("zw. pin 26");
  }
  if (rangeval == 2){
    digitalWrite(19, LOW);  
    digitalWrite(26, LOW);  
    digitalWrite(25, LOW);
    Serial.println("zw. pin none");
  }
  if (rangeval == 3) {
    digitalWrite(19, LOW);  
    digitalWrite(26, LOW);  
    digitalWrite(25, HIGH);
    Serial.println("zw. pin 25");
  }
  Serial.printf(" $$$$$$$$$$$$$$ rangeval, set range bigts = %d . bits 19,26,25 are set!\n\r", rangeval);

}


void RANGEmode() {
  char rbuf[5];
  int range;

  rangeval = readFile(SPIFFS, "/range.txt");
  rangebuf();
  Serial.printf("\n\t\tRANGE mode %d \n", modeval);
  display.clear();
  sprintf(pbuf, "RANGE Set  %s\n\n   cycle with UP arrow\n\t\t   SEL when done", rangebufdisplay);
  oled();



  while (3 == modeval) {
    // if (1 != modeval) break; // mode changed
    getUSD(); if (BUTTON == 1) {
      buttNum = 0; menunumber = 0;
      display.clear(); sprintf(pbuf, "BROKE RANGE"); oled(); display.display(); Serial.printf("\nB R O K E . out of RANGE mode\n\n");
      modeval++;
      delay(1000);
      break;
    }
    while (3 == modeval) {
      getUSD();
      if (BUTTON == 1) {
        display.clear(); display.display(); Serial.printf("\nB R O K E . out of RANGE mode\n\n");
        modeval++;
        delay(1000);
        break;
      }

      READadc1115();// is this too often?
      Thermostat();//  is this too often?

      if (BUTTON == 2) {
        Serial.print(sensorValue); Serial.println("inc.RANGE");

        rangeval += 1; if (rangeval >= 4) range = 0;
        sprintf(pbuf, "%03d", rangeval);
        writeFile(SPIFFS, "/range.txt", pbuf);
        rangebuf();
        strcpy(pbuf, rangebufdisplay);
        Serial.printf(pbuf);
        display.setFont(ArialMT_Plain_16);
        sprintf(rbuf, "x%03d", rangeval);

        oledFONT();
        delay(1000);
        writeFile(SPIFFS, "/range.txt", rbuf);
      }

      delay(200);

      READadc1115();// is this too often?
      Thermostat();//  is this too often?
    }
  }
}



//////////////////////////////

//////////////////////////////

//////////////////////////////
