void tempbutton() {
  int rv, temperaturein;
  char lampbuf[64];
  delay(1200);
  while (1) {

    int temperaturein = readFile(SPIFFS, "/temp.txt");
    newtemp=temperaturein;
    if (temperaturein > 10 && temperaturein < 301 ) sprintf(lampbuf, "TEMP is %d", temperaturein);
    else sprintf(lampbuf, "TEMP is farkled\n\r%d", temperaturein);

    Serial.printf("\t\t$$$  tepmbuf=%s\n\r", lampbuf);
    sprintf(pbuf,  "%s\n\rUp           Down\n\rS return ", lampbuf);
    Serial.println(pbuf);
    display.clear();
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.flipScreenVertically();
    display.setFont(ArialMT_Plain_16);
    oledFONTnoclear();
    display.display();
    Serial.printf("ReadWaiting for temp UP/DOWN\n\r");
    buttNum = 0;

    rv = ReadButtonAgainWaiting();

    if (2 == rv) {
      temperaturein = (temperaturein / 10) * 10;
      temperaturein += 10;
      if (temperaturein > 301) temperaturein = 20;
      sprintf(pbuf, "%03d", temperaturein);
      writeFile(SPIFFS, "/temp.txt", pbuf);
      delay(200);
    }
    if (3 == rv) {
      temperaturein -= 2;
      if (temperaturein < 0) temperaturein = 300;
      sprintf(pbuf, "%03d", temperaturein);
      writeFile(SPIFFS, "/temp.txt", pbuf);
      delay(200);
    }

 buttNum = 0; menunumber = 0;

    //menunumber = 3; // where to go when done with manual autozero
    if (1 == rv) {
      Serial.printf("GOT SEL BUTTON from tempset\n\r");
       buttNum = 0; menunumber = 0; modeval=0;
       delay(1000);
      //break;
      return; //$$
    };

  }
}
