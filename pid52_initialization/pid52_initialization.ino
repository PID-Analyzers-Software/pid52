#include "SPIFFS.h"
 
void setup() {
 
  Serial.begin(115200);
 
  if (!SPIFFS.begin(true)) {
    Serial.println("An Error has occurred while mounting SPIFFS");
    return;
  }
 
  File file = SPIFFS.open("/temp.txt", FILE_WRITE);
 
  if (!file) {
    Serial.println("There was an error opening the file for writing");
    return;
  }
  if (file.print("111")) {
    Serial.println("File was written");
  } else {
    Serial.println("File write failed");
  }
 
  file.close();

    File file2 = SPIFFS.open("/time.txt", FILE_WRITE);
 
  if (!file2) {
    Serial.println("There was an error opening the file for writing");
    return;
  }
  if (file2.print("001")) {
    Serial.println("File was written");
  } else {
    Serial.println("File write failed");
  }
 
  file2.close();

    File file3 = SPIFFS.open("/lamp.txt", FILE_WRITE);
 
  if (!file3) {
    Serial.println("There was an error opening the file for writing");
    return;
  }
  if (file3.print("000")) {
    Serial.println("File was written");
  } else {
    Serial.println("File write failed");
  }
 
  file3.close();

    File file4 = SPIFFS.open("/range.txt", FILE_WRITE);
 
  if (!file4) {
    Serial.println("There was an error opening the file for writing");
    return;
  }
  if (file4.print("001")) {
    Serial.println("File was written");
  } else {
    Serial.println("File write failed");
  }
 
  file4.close();
}
 
void loop() {}
