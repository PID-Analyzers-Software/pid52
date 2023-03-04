# pid52

# 303c 
- original software on the 52

# 304c 
- swap high voltage display and other modifications

# 305c
- updated the touchpad voltage.

# 306c
ADS1115: 4,5. Modify to Wire1.begin(4, 5);   in setup.h & ADS1115.h\
Display: 21, 22. Set SSD1306  display(0x3C, 21, 22);  in PID52.h\

# 307c:
add initialization code to create the internal memory space for parameters.

button votlage is set in menubutton.ino / PID52.h / readmembrane.ino 

# 401:
for the new PCB board design, button voltage adjusted.

# 403:
autozero time changed to 5 secs. ----jw

signals from adc are averaged by 10. ----jw

# 404:
added digits removed. Lamp check before running added. ----jw

Reduced waiting after the autozero, before the run. ----jw

# 405:
Modified Display. ----jw

# 406:
Updated button voltage ---jw 02/20/2023

# 407:
Problem: jumping into running mode.
Solution: Trigger button threshold increased to 1200 ~ 1V. 


    sensorV  += analogRead(15); //memb
    sensorV2 = analogRead(14);//temp
    sensorV3 = analogRead(12);//hv
    sensorV4 = analogRead(2);//bias
    sensorV5 = analogRead(26);//lamp status????
