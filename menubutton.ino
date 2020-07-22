

#if 1

void RunMode();


void MenuButton() {

  menunumber = 0;
  sprintf(pbuf, "%s",  menuitems[menunumber]);
  display.clear();
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_24);
  oledFONTnoclear();
  display.display();

  while (1) // check new menu tool, borrowed from internet.
  {
    char lampbuf[32];
    int rv;
    Thermostat();
    if ( buttonLastChecked == 0 ) // see if this is the first time checking the buttons
      buttonLastChecked = millis() + BUTTONDELAY; // force a check this cycle
    if ( millis() - buttonLastChecked > BUTTONDELAY ) { // make sure a reasonable delay passed
      if ( buttNum = buttonPushed(analogPin) ) {

        if (buttNum == 3) {
          menunumber++; if (!menuitems[menunumber][0])menunumber = 0;
          //Serial.printf("menunumber=%d\n\r", menunumber);
          Serial.printf("Button %d menunumber %d  modeval=%d depressed which is ::%s::\n\r", buttNum, menunumber, modeval, menuitems[menunumber]);
          sprintf(pbuf, "%s",  menuitems[menunumber]);
          display.clear();
          display.setTextAlignment(TEXT_ALIGN_LEFT);
          display.flipScreenVertically();
          display.setFont(ArialMT_Plain_24);
          oledFONTnoclear();
          display.display();
        }


        if (buttNum == 1) {
          if (menunumber == 0) {
            display.clear(); display.display(); delay(1000);
            RUNmode();
            buttNum = 0; menunumber = 0;
            return;
          }

          // the do stuff area of the menu
          if (menunumber == 1) {
            display.clear(); display.display(); delay(1000);
            JUSTheat();
            buttNum = 0; menunumber = 0;
            return;
          }
          if (menunumber == 2) {
            display.clear(); display.display(); delay(1000);
            AUTOZEROmode();
            buttNum = 0; menunumber = 0;
            return;
          }
          if (menunumber == 3) {
            display.clear(); display.display(); delay(1000);
            while (1) {
              Thermostat();
              persistantlamp = readFile(SPIFFS, "/lamp.txt");
              sprintf(lampbuf, "LAMP is farkled");
              if (0 == persistantlamp) sprintf(lampbuf, "LAMP is %s", "ON");
              if (1 == persistantlamp) sprintf(lampbuf, "LAMP is %s", "OFF");
              Serial.printf("\t\t$$$  persistantlamp=%d lampbuf=%s\n\r", persistantlamp, lampbuf);
              sprintf(pbuf,  "%s\n\rU=on  D=off\n\rS return ", lampbuf);
              Serial.println(pbuf);
              display.clear();
              display.setTextAlignment(TEXT_ALIGN_LEFT);
              display.flipScreenVertically();
              display.setFont(ArialMT_Plain_16);
              oledFONTnoclear();
              display.display();
              delay(1000);
              Serial.printf("delaying 1 sec;  ReadWaiting for UP=2\n\r");


              rv = ReadButtonAgainWaiting();

              pinMode(18, OUTPUT);  // lamp 0 on 1 off  (weird!!!)

              if (2 == rv) {
                writeFile(SPIFFS, "/lamp.txt", "000");
                digitalWrite(18, LOW);
              }
              if (3 == rv) {
                writeFile(SPIFFS, "/lamp.txt", "001");
                digitalWrite(18, HIGH);
              }
              buttNum = 0; menunumber = 0;
              if (1 == rv) {
                Serial.printf("SELECT EXIT rv == 1\n\r");
                buttNum = 0; menunumber = 0;
                // works with temp// display.clear(); display.display(); delay(1000);
                // break; //??
#if 1 //this works here
                display.clear();
                display.display();
                delay(1000);
                return;
#endif
              };

            }
          }

          if (menunumber == 4) {   //ooh this is the nice way to do this!
            display.clear(); display.display(); delay(1000);
            tempbutton();
            buttNum = 0; menunumber = 0;
            display.clear(); display.display(); delay(1000);
            break; //??
          }

          if (menunumber == 5) {
            display.clear(); display.display(); delay(1000);
            rangebutton();
            buttNum = 0; menunumber = 0;
            display.clear(); display.display(); delay(1000);
            break; //??
          }
          
          if (menunumber == 6) {
            display.clear(); display.display(); delay(1000);
            timebutton();
            buttNum = 0; menunumber = 0;
            display.clear(); display.display(); delay(1000);
            break; //??
          }
        }
      }
    }
    delay(PAUSEBUT);
    digitalWrite(17, -pin17); pin17 = ~pin17;
    //Serial.printf("\t\t\tpin17=%d\n",-pin17);
  }
  buttonLastChecked = millis(); // reset the lastChecked value
}


#endif

#if 1
int ReadButtonAgainWaiting() {
  delay(200);
  buttNum = buttonPushed(analogPin);
  while (buttNum == 0) {
    Thermostat();
    //Serial.println("waitng for new button");
    delay(200);
    if ( buttonLastChecked == 0 ) // see if this is the first time checking the buttons
      buttonLastChecked = millis() + BUTTONDELAY; // force a check this cycle
    if ( millis() - buttonLastChecked > BUTTONDELAY ) { // make sure a reasonable delay passed
      if ( buttNum = buttonPushed(analogPin) ) {
        //Serial.print("Button "); Serial.print(buttNum); Serial.println(" was pushed.");
      }
    }
  }
  return buttNum;
}
#endif


#if 1
#define UPBUT 1533
#define SELBUT 833
#define DOWNBUT 430
#define PAUSEBUT 345 // how long to pause before repeating a button

int buttonPushed(int pinNum) {  // routine open source from: https://forum.arduino.cc/index.php?topic=20125.0
  int val = 0;         // variable to store the read value
  //digitalWrite((14 + pinNum), HIGH); // enable the 20k internal pullup
  for (int kk = 0; kk < 100; kk++) val += analogRead(15); // read the input pin
  val = val / 100;
  //Serial.printf("pin 15 = %d\n",val);
#ifdef DEBUG_ON
  //Serial.println(val);
  //analogWrite(ledPin, val/4); // analog input 0-1023 while analogWrite 0-255
#endif
  // we don't use the upper position because that is the same as the
  // all-open switch value when the internal 20K ohm pullup is enabled.
  //if( val >= 923 and val <= 1023 )
  //  Serial.println("switch 0 pressed/triggered");
  if ( val >= DOWNBUT and val <= DOWNBUT ) { // 830
#ifdef DEBUG_ON
    //Serial.println("switch 1 pressed/triggered");
#endif
    return 1;
  }
  else if ( val >= (DOWNBUT - ERROR_WINDOW) and val <= (DOWNBUT + ERROR_WINDOW) ) { // 630
#ifdef DEBUG_ON
    //Serial.println("switch 2 pressed/triggered");
#endif
    return 2;
  }
  else if ( val >= (UPBUT - ERROR_WINDOW) and val <= (UPBUT + ERROR_WINDOW) ) { // 430
#ifdef DEBUG_ON
    //Serial.println("switch 3 pressed/triggered");
#endif
    return 3;
  }
  else if ( val >= (SELBUT - ERROR_WINDOW) and val <= (SELBUT + ERROR_WINDOW) ) { // 230
#ifdef DEBUG_ON
    //Serial.println("switch 4 pressed/triggered");
#endif
    return 1; // was 4
  }
  else
    return 0;  // no button found to have been pushed
}
#endif
