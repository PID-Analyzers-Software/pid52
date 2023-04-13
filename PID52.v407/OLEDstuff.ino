//================================================================   D I S P L A Y    S T U F F



void DisplayREADY() {

  sprintf(pbuf, "PID52\n\rREADY");
  Serial.print(pbuf);
  display.clear();
  oled();
  delay(476); // was 476
  modeval = 0;
}

void oled() {

  // if (0 != sensorValue) {
  //Serial.println("oled()");

  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_10);
  // print out the value you read:
  //Serial.println(pbuf);
#if 0
  sprintf(pbuf, " counter2 = %d\n\r", counter2++);

#endif
  display.drawString(0, 5, pbuf);
  delay(50);
  display.display();
  delay(200);
  //$$ bbl display.clear();
  //}
}

//================================================================   O L E D ( )    display function


//================================================================   O L E D ( )    display function





void oledFONT() {

  // if (0 != sensorValue) {
  //Serial.println("oled()");

  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.flipScreenVertically();
  display.drawString(0, 5, pbuf);
  delay(50);
  display.display();
  delay(200);
  display.clear();
  //}
}


void oledFONTnoclear() {

  // if (0 != sensorValue) {
  //Serial.println("oled()");

  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.flipScreenVertically();
  display.drawString(0, 5, pbuf);
  delay(50);
  display.display();
  //delay(200);
  //display.clear();
  //}
}

//================================================================   O L E D ( )    display function






//================================================================   D I S P L A Y   L A M P   M O D E



void StartupDisplay() {



  //delay(7000);

  Serial.println("");  Serial.println("");  Serial.println("");  Serial.println("");  Serial.println("");
  Serial.print("starting:");  Serial.println(SRCREV);
  Serial.print("starting:");  Serial.println(SRCREV);
  Serial.print("starting:");  Serial.println(SRCREV);
  Serial.print("starting:");  Serial.println(SRCREV);
  Serial.println("");  Serial.println("");
  //delay(4000);


  //    init stuff
  display.clear();
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_10);
  display.drawString(0, 5, SRCREV);
  display.display();
  delay(1500);

  display.clear();
  //sprintf(pbuf, "starting\n\r%s", SRCREV);
  //oled();
  //delay(476);


}

///////////////////////////////////  oledPrettyScreen
///////////////////////////////////  oledPrettyScreen
///////////////////////////////////  oledPrettyScreen
///////////////////////////////////  oledPrettyScreen

void  oledPrettyScreen(char *HV, char *BIAS, char *MESSAGE, int font, char *range, char *temp) {

  Serial.println("oled()");
  display.clear();
  display.flipScreenVertically();
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.setFont(ArialMT_Plain_10);
//  sprintf(pbuf, "%s  %s\n\r", HV, BIAS);
//  display.drawString(0, 5, pbuf);
  display.setFont(ArialMT_Plain_10);
  if (16 == font) display.setFont(ArialMT_Plain_16);
  if (24 == font ) {
    sprintf(pbuf, MESSAGE);
    display.setFont(ArialMT_Plain_24);
    display.drawString(0, 20, pbuf);
    sprintf(pbuf, "V");
    display.setFont(ArialMT_Plain_16);
    display.drawString(99, 26, pbuf);
  }
  else {
    sprintf(pbuf, MESSAGE);
    display.drawString(0, 26, pbuf);
  }
  display.setFont(ArialMT_Plain_10);
  sprintf(pbuf, "%s %s\n\r", range, temp);
  display.drawString(0, 50, pbuf);
  delay(100);
  display.display();


}
