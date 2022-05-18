#if 1
int ReadButtonAgainWaiting();
#define ERROR_WINDOW 50  // was 50 +/- this value
#define BUTTONDELAY 200 // was 100 was 50 was 20 $$
#define DEBUG_ON
#define PAUSEBUT  1000 // was 900 was 647 how long to wait to repeat button
int menunumber = 0;
int actionmode = 0;
int buttNum = 0;

int pin17 = 0; // the relay clicker
int ledPin = 9;      // LED connected to digital pin 9
int analogPin = 3;   // switch circuit input connected to analog pin 3
long buttonLastChecked = 0; // variable to limit the button getting checked every cycle
int buttonPushed(int pinNum);

char buf[10] = {'a', 0, 0, 0, 0, 0, 0, 0, 0, 0};
char menuitems[][40] = {"RUN\n\r  S to start", "set lamp", "set temp", "set range","set runtime",""};
//                        0                     1 .                       2 .                         3 .     4           4       5   
#endif
