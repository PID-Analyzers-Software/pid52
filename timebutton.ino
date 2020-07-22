void timebutton() {
  int rv;
  char lampbuf[64];
  delay(1200);
  while (1) {

    timein = readFile(SPIFFS, "/time.txt");
    
    if (timein >= 1 && timein < 31 ) sprintf(lampbuf, "Run = %d mins", timein);
    else sprintf(lampbuf, "Runtime=farkled\n\r%d", timein);

    Serial.printf("\t\t$$$  timebuf=%s\n\r", lampbuf);
    sprintf(pbuf,  "%s\n\rUp           Down\n\rS return ", lampbuf);
    Serial.println(pbuf);
    display.clear();
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.flipScreenVertically();
    display.setFont(ArialMT_Plain_16);
    oledFONTnoclear();
    display.display();
    Serial.printf("ReadWaiting for time UP/DOWN\n\r");
    buttNum = 0;

    rv = ReadButtonAgainWaiting();

    if (2 == rv) {
      timein = (timein / 10) * 10;
      timein += 10;
      if (timein > 31) timein = 1;
      sprintf(pbuf, "%03d", timein);
      writeFile(SPIFFS, "/time.txt", pbuf);
      delay(600);
    }
    if (3 == rv) {
      timein -= 1;
      if (timein <= 0) timein = 30;
      sprintf(pbuf, "%03d", timein);
      writeFile(SPIFFS, "/time.txt", pbuf);
      delay(600);
    }

 buttNum = 0; menunumber = 0;

    //menunumber = 3; // where to go when done with manual autozero
    if (1 == rv) {
      Serial.printf("GOT SEL BUTTON from timeset\n\r");
       buttNum = 0; menunumber = 0; modeval=0;
       delay(1000);
      //break;
      return; //$$
    };

  }
}
