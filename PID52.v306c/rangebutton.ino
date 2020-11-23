void rangebutton() {
  char rangeitems[][20] = {"x1", "x10", "x100", "x1000",""};
  int rv, rangein;
  char lampbuf[64];
  while (1) {

    display.display();
    rangein=readFile(SPIFFS,"/range.txt");
    Serial.printf("ReadWaiting for RANGE UP/DOWN\n\r");
    buttNum = 0;
    sprintf(lampbuf,"range is %s",rangeitems[rangein]);
    Serial.printf("\t\t$$$  range is %s\n\r", rangeitems[rangein]);
    strcpy(rangebufdisplay,rangeitems[rangein]);
    sprintf(pbuf,  "%s\n\rUp           Down\n\rS return ", lampbuf);
    Serial.println(pbuf);
    display.clear();
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.flipScreenVertically();
    display.setFont(ArialMT_Plain_16);
    oledFONTnoclear();
    display.display();
  
    rv = ReadButtonAgainWaiting();

    if (2 == rv) {
      rangein += 1;
      if (rangein > 3) rangein = 0;
      sprintf(pbuf, "%03d", rangein);
      writeFile(SPIFFS, "/range.txt", pbuf);
      delay(100);
    }
    if (3 == rv) {
      rangein -= 1;
      if (rangein < 0) rangein = 3;
      sprintf(pbuf, "%03d", rangein);
      writeFile(SPIFFS, "/range.txt", pbuf);
      delay(100);
    }

    rangebuf();   // SET THE RANGE BITS FOR THE BRETmeister
    
    menunumber = 3; // where to go when done with range
    if (1 == rv) {
      menunumber = 0;
      break;
    };
  }
}
