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
