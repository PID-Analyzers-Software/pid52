
//================================================================   do lots of stuff

//================================================================

void CheckMode() {
  
  //Serial.print(" checkmode  ");  Serial.print(modeval); Serial.print(" "); Serial.println(loopcount++);

  if (BUTTON) { // no button pressed

    if (BUTTON == 1) modeval++;
    if (modeval >= 4) modeval = 0;
  }
}

#if 0
Serial.print(sensorValue);    Serial.print(" checkmode  ");  Serial.print(modeval); Serial.print(" "); Serial.println(loopcount++);

// MEMBRANE  switch voltage           nada.0-20
//
//
//                       S 750-850 . UP 360-410 . DOWN 1450-1550 .  nothing <= 40

//================================================================   S E L E C T

//   set the mode switch (far left SELECT switch  2815
if (sensorValue > Slow && sensorValue <= Shi) {
  Serial.print(sensorValue);
  delay(30);  //was 100
  modeval++;
  if (modeval >= 4) modeval = 0;

  Serial.printf(" MODE = %d\n", modeval);  delay(100);
  sprintf(pbuf, " MODE = %d\n", modeval);
  display.clear();
  oled();
}





//================================================================   C H A N G E   T E M P

//================================================================   increment T
if (1 == modeval) {


  if (sensorValue > Ulow && sensorValue < Uhi) {

    Serial.print(sensorValue); Serial.println("inc.Uhi");
    int temptemp = newtemp;
    temptemp = (newtemp / 10) * 10;
    newtemp = temptemp + 10;
    if (newtemp >= 301) newtemp = 20;
    if (newtemp != oldnewtemp) {
      sprintf(pbuf, "%03d", newtemp);  // write the temp they request
      writeFile(SPIFFS, "/temp.txt", pbuf);
      oldnewtemp = newtemp;
    }
  }
  //================================================================   decrement T

  if (sensorValue > Ulow && sensorValue < Uhi) {//dec.
    Serial.print(sensorValue); Serial.println("Ulow");
    newtemp = newtemp - 2;
    if (newtemp < 20) newtemp = 250;
    sprintf(pbuf, "%03d", newtemp);  // write the temp they request
    writeFile(SPIFFS, "/temp.txt", pbuf);
    display.clear();
    oled();

  }

}



//================================================================   M O D E   2 LAMP

if (modeval == 2)   {
  Serial.println("MODE NOW:    lamp");
  display.clear();
  sprintf(pbuf, "LAMP\n\rmode");
  oled();
  delay(50);
}



//================================================================   M O D E   3 autozero

if (modeval == 3)   {
  Serial.println("MODE NOW:    lamp");
  display.clear();
  sprintf(pbuf, "LAMP\n\rmode");
  oled();
  delay(50);
}


} //end no button pressed, to keep the special modes, like READY
}
#endif
