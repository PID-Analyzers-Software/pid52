void JUSTheatcheck();

void JUSTheatcheck() {
  char rangebufdisplay[64];
  char rangeitems[][20] = {"x1", "x10", "x100", "x1000", ""};
  Serial.printf("\n\t\tRUN mode %d \n", modeval);

  int rangein = readFile(SPIFFS, "/range.txt");
  //  int rangein = 1;

  rangebufdisplay[0] = 0;
  sprintf(rangebufdisplay, "%s", rangeitems[rangein]); // shorten range to include runtime
  //sprintf(rangebufdisplay, "Range = %s", rangeitems[rangein]);

  rangebufdisplay[0] = 0;
  Serial.printf("\t\t$$$  range is %s\n\r", rangebufdisplay);

  Serial.println("zw readadc started");
  READadc1115();// is this too often?
  Serial.println("zw readadc finished");
  Serial.println("zw thermostat started");

  Thermostat();//  is this too often?
  Serial.println("zw thermostat finished");

  counter = 0;

  delay(500);

  starttime = millis();

  while (1) {

    Thermostat();
    if (buttonPushed(15) == 1) {
      display.clear(); display.display(); Serial.printf("\t\tB R O K E\n\n");
      delay(1000);
      break;
    }
#if 0
    if (buttonPushed(15) == 3) {
      menunumber = 0;
      display.clear(); display.display(); Serial.printf("\t\treturn return return\n\n");
      delay(1000);
      return;
    }
#endif

    READadc1115();// is this too often?
    Thermostat();//  is this too often?



    sprintf(temperbuf, "    setting: %d C\n\r                  press S to Start", newtemp);
    sprintf(temperactual, " T = %d C", currtemp);
    int rangein = readFile(SPIFFS, "/range.txt");
    rangebufdisplay[0] = 0;
    //sprintf(rangebufdisplay, "Range = %s", rangeitems[rangein]);  // bbl shorten range, to add runtime
    sprintf(rangebufdisplay, "%s", rangeitems[rangein]);



    //////////////////   very good here, bad bradshaw 7/12/2020


    //  bbl going to add in runtime to the range display, sleazy, but quick, and less hours and $$$$$ to QA test the code
    runsecs = ((millis() - starttime) / 1000) % 60;
    runmins = (millis() - starttime) / 60000;


    sprintf(rangebufdisplay, "% R = %s", rangeitems[rangein]); // bbl shortened range to inculde runtime
    //sprintf(rangebufdisplay, "Range = %s", rangeitems[rangein]);

    //////////////////

    Serial.printf("\t\t$$$  range is %s\n\r", rangebufdisplay);
    //Serial.println("zw start highvoltage _ jstheat");
    //    if (HIGHVOLTAGE < 50. )
    //      sprintf(HVbuf, "HV *out*", (float)HIGHVOLTAGE);     // bias and high voltages were swapped  7/12/2020 bbl
    //    else                                                  // bradshaw, bad bradshaw, just swapped the display
    sprintf(HVbuf, "HV = %.0f V  % d s", (float)HIGHVOLTAGE, (30 - (millis() - starttime) / 1000)); //  however, this change requires no QA retest, nor big change
    //  so it is a 1 hour changed, rather than a 6 hour $$$$ change. my bad
    //    if (BIASVOLTAGE < 20.)
    //      sprintf(BIASbuf, "Bias *out*", (float)BIASVOLTAGE);
    //    else
    sprintf(BIASbuf, "Bias = %.0f V", (float)BIASVOLTAGE);

    oledPrettyScreen(HVbuf, BIASbuf , temperbuf, 10, rangebufdisplay, "*heating*");
    if (buttonPushed(15) == 1) {
      display.clear(); display.display(); Serial.printf("\t\tB R O K E\n\n");
      delay(1000);
      break;
    }
    if (buttonPushed(15) == 3) {
      menunumber = 0;
      display.clear(); display.display(); Serial.printf("\t\treturn return return\n\n");
      delay(1000);
      return;
    }
    delay(250);
    rangebufdisplay[0] = 0;
    //  sprintf(rangebufdisplay, "Range = %s", rangeitems[rangein]);
    sprintf(rangebufdisplay, "%s", rangeitems[rangein]);// bbl shorten range to include runtime

    //////////////////


    //  bbl going to add in runtime to the range display, sleazy, but quick, and less hours and $$$$$ to QA test the code
    runsecs = ((millis() - starttime) / 1000) % 60;
    runmins = (millis() - starttime) / 60000;


    sprintf(rangebufdisplay, " R = %s", rangeitems[rangein]); // bbl shortened range to inculde runtime
    //sprintf(rangebufdisplay, "Range = %s", rangeitems[rangein]);

    //////////////////
    oledPrettyScreen(HVbuf, BIASbuf, temperbuf, 10, rangebufdisplay, temperactual);
    if (buttonPushed(15) == 1) {
      display.clear(); display.display(); Serial.printf("\t\tB R O K E\n\n");
      delay(1000);
      break;
    }
    if (buttonPushed(15) == 3 or millis() - starttime > 2000) {
      menunumber = 0;
      display.clear(); display.display(); Serial.printf("\t\treturn return return\n\n");
      delay(1000);
      return;
    }
    delay(250);
  }

  Serial.printf("out of wait for wait for temp \n");
}
