

void setup() {
  pinMode(33, OUTPUT);   digitalWrite(33, LOW); // set autozero low
  pinMode(18, OUTPUT);  // lamp 0 on 1 off  (weird!!!)
#if 0  // cycle lamp 18 on off  T E S T
  while ( 1 ) {
    digitalWrite(18, HIGH);
    delay(3000);
    digitalWrite(18, LOW);
    delay(3000);
  }
#endif
  Wire1.begin(5, 4);
  Serial.begin(115200);
  display.init();
  ads.begin();
  delay(500); Serial.println(); Serial.println(SRCREV); Serial.println(SRCREV); Serial.println(SRCREV); delay(1000);
  delay(500); Serial.println(); Serial.println(SRCREV); Serial.println(SRCREV); Serial.println(SRCREV); delay(2000);
  
#if 0 // add to cool test

   AUTOZEROwait(); // test the hell out of this, wait for 5 v signal to continue, or S to skip or DOWN to skip
                   // this waits for 5v OR butt push .  bradshaw 8/7/19

#endif

#if 0 //reads and returns.

  // quick button pushed test
  while (1) {
    Serial.printf("buton = buttonPushed(15)=%d v=%d\n\r", buttonPushed(15),analogRead(15));
    delay(50);
  }
#endif


#if 0 // DO ONCE, then upload data  // keep here for fresh unit. format, upload Esp32 sketch data, test!!! bradshaw 7/15/19

  Serial.println("\n\nSPIFFSformatting");
  bool formatted = SPIFFS.format();
  if (formatted) {
    Serial.println("\n\nSuccess formatting");
  } else {
    Serial.println("\n\nError formatting");
  }
#endif



  Serial.println("SPIFFS.begin");

  if (!SPIFFS.begin(FORMAT_SPIFFS_IF_FAILED)) {
    Serial.println("SPIFFS Mount Failed");
    delay(60000);
    return;
  }



#if 0  // this is just neat and handy

  listDir(SPIFFS, "/", 0);
  delay(9000);

#endif

  display.init();
  display.clear();

  StartupDisplay();

  modeval = 0; // play display ready


  //////// . read the three files
  pinMode(18, OUTPUT);
  persistantlamp = readFile(SPIFFS, "/lamp.txt");
  if (persistantlamp == 1)
  {
    digitalWrite(18, HIGH);
  }
  else
  {
    digitalWrite(18, LOW);
  }

  newtemp = readFile(SPIFFS, "/temp.txt");
  Serial.printf("newtemp=%d\n\r",newtemp);

  range = readFile(SPIFFS, "/range.txt");
    Serial.printf("range=%d\n\r",range);

    
  timein = readFile(SPIFFS, "/time.txt");
    Serial.printf("range=%d\n\r",timein);


#if 0
  sprintf(pbuf, "READING $$ temp.txt=%d", range);
  display.clear();
  oled();
  delay(1500);
#endif

  //rangebuf();




  // for debug:  while (1) READadc1115();  // check out the voltages
  // for debug:  while (1) Thermostat();   // get the temp up to 251C which is 2815 on pin D14, pin D13 is heater on/off

}
