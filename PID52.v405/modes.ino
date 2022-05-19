//================================================================   
//================================================================   HANDLE MODES
//================================================================   


//================================================================   S E T   T E M P E R A T U R E


void SetTemperatureMode() {      //temp is about 18 in the room,  92 in hot water. will accept.



  //   1993/2056    INC               up/down T set, and lamp on/off
  //   1845/1880    DEC


  display.clear();
  sprintf(pbuf, "Set: %d C\nT= %d C", newtemp, temp14);
  oled();
  delay(476);



}    // end of set temperature mode



//================================================================   D I S P L A Y   L A M P   M O D E



void LampMode() {

  if (lamp == 1) {
    sprintf(pbuf, "LAMP  off\n\r%d V", (1000 * hv12) / 762);
  } else {
    sprintf(pbuf, "LAMP  on\n\r%d V", (1000 * hv12) / 762);
  }



  Serial.print(pbuf);
  display.clear();
  oled();
  delay(476);



}

//================================================================   D I S P L A Y   H I G H   V O L T A G E   M O D E


void HighVoltageMode() {


  sprintf(pbuf, "High\n\r%d V", (1000 * hv12) / 762);
  Serial.print(pbuf);
  display.clear();
  oled();
  delay(476);

}    // end of high voltage



//================================================================   D I S P L A Y   B I A S   V O L T A G E   M O D E



void BiasVoltageMode() {


  sprintf(pbuf, "bias\n\r%d V", (100 * bias2) / 762);
  Serial.print(pbuf);
  display.clear();
  oled();
  delay(476);
}    // end of bias voltage


//================================================================   R E A D Y   M O D E   s a v e   temp/lamp
