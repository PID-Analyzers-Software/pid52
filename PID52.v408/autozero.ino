#if 1
float AUTOZEROmode()  {
 
  Serial.printf("AUTOZERO mode STARTING\n\r"); delay(100);
  AUTOZEROit();
  Serial.printf("AUTOZERO mode complete\n\r");
  Serial.printf("AUTOZERO mode complete\n\r");
  Serial.printf("AUTOZERO mode complete . sitting for 0 secs\n\r");
}
int zz, yy;
float AUTOZEROit() {
  Serial.printf("AUTOZEROit STARTING\n\r"); delay(100);
  AUTOZEROwait();  // this waits for 5V or button press
  //  float AUTOZEROmode() {
  pinMode(33, OUTPUT);   digitalWrite(33, HIGH);
  READadc1115();// is this too often?
  Thermostat();//  is this too often?
  long oldmillis = millis();
  display.clear();
  // bbl maybe remove sprintf(pbuf, "AUTOZERO \nuntil trigger\n\rdrops");
  //Serial.println(pbuf);
  //display.setFont(ArialMT_Plain_16);
  //oledFONT();

  display.clear();
  oldmillis = millis();

  for (zz = yy = 0; zz < 100; zz++) yy = analogRead(32);

// WAS:  while ( yy > 10 ) { // Wait for trigger to drop, or BUTT = 1 or 3

// NOW: reverse the yy test  to  yy < 10

   while ( yy < 10 ) { // Wait for trigger to go up , or BUTT = 1 or 3
    for (zz = yy = 0; zz < 100; zz++) yy = analogRead(32);

    READadc1115();// is this too often?
    Thermostat();//  is this too often?
    sprintf(autozerobuf, "  waiting for autozero % .1f", signalin);
  
    sprintf(temperactual, " T = % d C", currtemp);
    
    modeval = 0;



    READadc1115();// is this too often?
    Thermostat();//  is this too often?
    ////////////////////////////////////////////
    // 7/12/20 bbl, jack wants simple autozero
    ////////////////////////////////////////////
    //sprintf(pbuf, " triggered % .1f s\n\r sig = % .1f V\n\r   S to skip\n\r", ((float)(millis() - oldmillis) / 1000.), signalin);
        sprintf(pbuf, "     press S    % d s\n\rwhen volts stable\n\r     sig = % .1f V\n\r", (5-(millis() - oldmillis)/1000),signalin);
       //     sprintf(pbuf, "     press S  30s\n\rwhen volts stable\n\r     sig = % .1f V\n\r", signalin);

    ////////////////////////////////////////////
    // 7/12/20 bbl, jack wants simple autozero
    ////////////////////////////////////////////
    
    display.setFont(ArialMT_Plain_16);
    oledFONTnoclear();
    display.display();
    delay(380);
    display.clear();
    
    int butt = buttonPushed(analogPin);  // drop trigger, roy and dale, or hit S or Down arrow
    Serial.printf(" butt=%d   \n\r ", butt);
// was yy < 10
// not yy > 10
Serial.println(millis() - oldmillis);
    if (millis()-oldmillis > 5000) {
      Serial.printf("\n\n TIME OUT DONE autozerowaitn\r"); delay(100);
      display.clear();
      display.display();
      delay(600);
      break;
    }
    if (butt == 1 || butt == 3) {
      Serial.printf("\n\n GOT BUTT; DONE autozerowaitn\r"); delay(100);
      display.clear();
      display.display();
      delay(600);
      break;
    }
    modeval = 0;
  }
  sprintf(pbuf, "AUTOZERO \ncomplete!");

  display.setFont(ArialMT_Plain_16);
  oledFONTnoclear();
  display.display();
  delay(1000);
  READadc1115();// is this too often?
    Serial.println("jw readadc finished");
  Thermostat();//  is this too often?
    Serial.println("jw thermostat finished");

  autozeroVALUE = signalin;
    Serial.println("jw autoreset finished");

  pinMode(33, OUTPUT);   digitalWrite(33, LOW);
    Serial.println("jw pin reset finished");

  Serial.printf("AUTOZEROit ending\n\r"); delay(100);
  return signalin;

}

void AUTOZEROwait() {
  ///////////////////////////////////////////
  // 7/12/20 bbl, jack wants no trigger wait.
  return;
  ///////////////////////////////////////////
  
  oldmillis = millis();
  while (1) {

    Thermostat();//  is this too often?
    sprintf(pbuf, " % .1f secs\n\rAwaiting Trigger\n\r   S to skip\n\r", ((float)(millis() - oldmillis) / 1000.));
    display.setFont(ArialMT_Plain_16);
    oledFONTnoclear();
    display.display();
    delay(380);
    display.clear();

    Serial.printf("AUTOzerowait STARTING\t\t"); delay(100);
    for (zz = yy = 0; zz < 100; zz++) {
      yy = analogRead(32);
      delay(10);
    }
    Serial.printf("autozero wait %d\t\t", yy / 100);
    int butt = buttonPushed(analogPin);
    Serial.printf(" butt=%d    ", butt);
    Serial.printf("AUTOzerowait ending\n\r"); delay(100);

// WAS yy> 10

// NOW reverse the test   bradshaw 10/15/19
    
    if (yy < 10) {
      Serial.printf("\n\n GOT 5V signal DONE autozerowaitn\r"); delay(100);
      display.clear();
      display.display();
      delay(600);
      break;
    }
    if (butt == 1 || butt == 3) {
      Serial.printf("\n\n GOT BUTT; DONE autozerowaitn\r"); delay(100);
      display.clear();
      display.display();
      delay(600);
      break;
    }
  }

}
void AUTOZEROstop() {
  Serial.printf("AUTOZEROstop STARTING\n\r"); delay(100);
  Serial.printf("AUTOZEROstop ending\n\r"); delay(100);
}


#else
#if 1 // just for now
int AutoZeroSTOP() {  // stop if the autozero signal goes away
  int zz; int yy; zz = yy = 0;
  for (zz = yy = 0; zz < 100; zz++) yy = analogRead(32);
  delay(100);
  Serial.printf("AutoZeroSTOP value = % d\n\r", yy / 100);

// WAS    if (yy / 100 < 20 ) return 1; else return 0;

// NOW  reverse the test

  if (yy / 100 > 20 ) return 1; else return 0;
}
int AutoZeroWait() {
  int zz; int yy; zz = yy = 0;
  for (zz = yy = 0; zz < 100; zz++) yy += analogRead(32);
  long WAITING = millis();
  while (yy / 100 < 20 ) {
    for (zz = yy = 0; zz < 100; zz++) yy += analogRead(32);
    READadc1115();// is this too often?
    Thermostat();//  is this too often?
    Serial.printf("yy, autozerowait = % d\n\r", yy / 100);
    delay(1000); //$$
    // was not here

    display.clear();
    sprintf(pbuf, "Waiting for \n\rautozero signal for \n\r % .2f min\n\r  S to manual autozero", (float)(millis() - WAITING) / 60000.);
    oled();
    if (buttonPushed(15) == 1  ) {  //|| AutoZeroSTOP()
      display.clear(); display.display(); Serial.printf("\t\tB R O K E\n\n");
      delay(1000);
      break;
    }
    delay(100);
  }// was brace here $$
  display.clear(); display.display();
  sprintf(pbuf, "GOT AUTOZERO START !");
  oled();
  delay(2000);
  //AUTOZEROONCE = 0;
  return 50;
}



float AUTOZEROmode() {
  // TEST

  pinMode(33, OUTPUT);   digitalWrite(33, HIGH);
  READadc1115();// is this too often?
  Thermostat();//  is this too often?
  long oldmillis = millis();
  display.clear();
  sprintf(pbuf, "AUTOZERO \n   next 5 seconds");
  Serial.println(pbuf);
  display.setFont(ArialMT_Plain_16);
  oledFONT();

  while ( AutoZeroWait() < 8) {

    READadc1115();// is this too often?
    Thermostat();//  is this too often?
    delay(100);
  }
  display.clear();
  oldmillis = millis();
  //for (int zz = 0; zz < 4; zz++) {
  for (int zz = 0; AutoZeroSTOP(); zz++) {


    READadc1115();// is this too often?
    Thermostat();//  is this too often?
    sprintf(autozerobuf, "  waiting for autozero % .1f", signalin);

    sprintf(temperactual, " T = % d C", currtemp);
    modeval = 0;



    READadc1115();// is this too often?
    Thermostat();//  is this too often?
    sprintf(pbuf, " % .1f secs\n\rsignalin\n\r = % .1f V", ((float)(millis() - oldmillis) / 1000.), signalin);
    display.setFont(ArialMT_Plain_16);
    oledFONTnoclear();
    display.display();
    delay(1500);
    display.clear();

    modeval = 0;
  }
  sprintf(pbuf, "AUTOZERO \ncomplete!");

  display.setFont(ArialMT_Plain_16);
  oledFONTnoclear();
  display.display();
  delay(1000);

  READadc1115();// is this too often?
  Thermostat();//  is this too often?
  autozeroVALUE = signalin;
  ZEROED = 0;
  pinMode(33, OUTPUT);   digitalWrite(33, LOW);
  return signalin;
}
#endif
#endif
