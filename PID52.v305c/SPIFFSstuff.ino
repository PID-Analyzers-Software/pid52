//================================================================   S P I F F S   stuff

#if 1 // original code

int readFile(fs::FS &fs, const char * path) {
  static int valuereadfromfile = 0;
  //Serial.printf("             $$$ . in readFile %s\n\n", path);
  int a = b = c = -1;
  int fileVal;
  char qbuf[64];
  //Serial.printf("\n      $$$$ . Reading file: %s\r\n", path);
  File file = fs.open(path);
  if (!file || file.isDirectory()) {
    Serial.println("- failed to open file for reading");
    return -1;
  }
  //Serial.println("- read from file:");

  if (file.available()) {
    if (-1 == a) {
      a = file.read();
      //if (path[0] == 'r' && path[1] == 'ea') a = 48;
    //  Serial.printf("::%c::", a);
    }
  }

  if (file.available()) {
    if (-1 == b) {
      b = file.read();
      //if (path[0] == 'r' && path[1] == 'a') b = 48;
      //Serial.printf("::%c::", b);
    }
  }

  if (file.available()) {
    if (-1 == c) {
      c = file.read();
      //Serial.printf("::%c::", c);
    }
  }
  sprintf(qbuf, "\t:a = %d  b = %d c=%d :\n\r", a - 48, b - 48, c - 48);
  //Serial.println(pbuf);
  //delay(2000);
  valuereadfromfile = (a - 48 ) * 100 + (b - 48) * 10 + c - 48;
  sprintf(pbuf, "\t: %s $$  :: %s ::  fileVal= %d :\n\r", path, qbuf, valuereadfromfile);
  Serial.printf("%s", pbuf);
#if 0
  display.clear();
  oled();
  delay(2500);
#endif



  while (file.available()) {
    Serial.write(file.read());
  }
  return valuereadfromfile;
}



void writeFile(fs::FS & fs, const char * path, const char * message) {
  Serial.printf("Writing file: %s, message: %s\r\n", path, message);
  File file = fs.open(path, FILE_WRITE);
  if (!file) {
    Serial.println("- failed to open file for writing");
    return;
  }
#if 0  // debug the crappy temp.txt file
  sprintf(pbuf, "%d %s\n\r%s", file, path, message);
  display.clear();
  oled();
  delay(1500);
#endif
  if (file.print(message)) {
    //Serial.println("- file written");
  } else {
    Serial.println("- frite failed");
  }
}
#endif


void listDir(fs::FS &fs, const char * dirname, uint8_t levels) {
  Serial.printf("Listing directory: %s\r\n", dirname);
  File root = fs.open(dirname);
  if (!root) {
    Serial.println("- failed to open directory");
    return;
  }
  if (!root.isDirectory()) {
    Serial.println(" - not a directory");
    return;
  }
  File file = root.openNextFile();
  while (file) {
    if (file.isDirectory()) {
      Serial.print("  DIR : ");
      Serial.println(file.name());
      if (levels) {
        listDir(fs, file.name(), levels - 1);
      }
    } else {
      Serial.print("  FILE: ");
      Serial.print(file.name());
      Serial.print("\tSIZE: ");
      Serial.println(file.size());
    }
    file = root.openNextFile();
  }
}


void testFileIO(fs::FS &fs, const char * path) {
  Serial.printf("Testing file I/O with %s\r\n", path);
  static uint8_t buf[512];
  size_t len = 0;
  File file = fs.open(path, FILE_WRITE);
  if (!file) {
    Serial.println("- failed to open file for writing");
    return;
  }
  size_t i;
  Serial.print("- writing" );
  uint32_t start = millis();
  for (i = 0; i < 2048; i++) {
    if ((i & 0x001F) == 0x001F) {
      Serial.print(".");
    }
    file.write(buf, 512);
  }
  Serial.println("");
  uint32_t end = millis() - start;
  Serial.printf(" - %u bytes written in %u ms\r\n", 2048 * 512, end);
  file.close();
  file = fs.open(path);
  start = millis();
  end = start;
  i = 0;
  if (file && !file.isDirectory()) {
    len = file.size();
    size_t flen = len;
    start = millis();
    Serial.print("- reading" );
    while (len) {
      size_t toRead = len;
      if (toRead > 512) {
        toRead = 512;
      }
      file.read(buf, toRead);
      if ((i++ & 0x001F) == 0x001F) {
        Serial.print(".");
      }
      len -= toRead;
    }
    Serial.println("");
    end = millis() - start;
    Serial.printf("- %u bytes read in %u ms\r\n", flen, end);
    file.close();
  } else {
    Serial.println("- failed to open file for reading");
  }
}


void appendFile(fs::FS &fs, const char * path, const char * message) {
  Serial.printf("Appending to file: %s\r\n", path);
  File file = fs.open(path, FILE_APPEND);
  if (!file) {
    Serial.println("- failed to open file for appending");
    return;
  }
  if (file.print(message)) {
    Serial.println("- message appended");
  } else {
    Serial.println("- append failed");
  }
}
void renameFile(fs::FS &fs, const char * path1, const char * path2) {
  Serial.printf("Renaming file %s to %s\r\n", path1, path2);
  if (fs.rename(path1, path2)) {
    Serial.println("- file renamed");
  } else {
    Serial.println("- rename failed");
  }
}
void deleteFile(fs::FS &fs, const char * path) {
  Serial.printf("Deleting file: %s\r\n", path);
  if (fs.remove(path)) {
    Serial.println("- file deleted");
  } else {
    Serial.println("- delete failed");
  }
}
