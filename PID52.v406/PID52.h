long timein;
float timeremaining;
float elapsedtime;
long runmins =0;
long runsecs=0;
long starttime=0;

//setting is in menubutton.h
#define Slow 900
#define Shi  1000
#define Dlow 1560
#define Dhi  1760
#define Ulow 360
#define Uhi 560
// changed to new analog range. j.w. 11/12
long oldmillis=0;
void AUTOZEROwait();
void AUTOZEROstop();
float AUTOZEROit();
int functionwithinmode = 0;
void RUNmode();
void JUSTheat();
void JUSTheatcheck();
void tempbutton();
void rangebutton();
char rbuf[64];
int AutoZeroWait();
float autozeroVALUE;
int AUTOZEROONCE = 1;
int ZEROED = 1;
void oledFONTnoclear();
void   oledFONT();
int AutoZero();
void      READadc1115();
void      Thermostat();
void   rangebuf();
void RANGEmode();
void MenuButton();
int AutoZeroSTOP();
int rangeval = 1;

char signalinbuf[64];
char temperbuf[64];
char rangebufdisplay[64];
char autozerobuf[64];
char temperactual[64];
int currtemp = 0;
char HVbuf[64];
char BIASbuf[64];

int kk;
int tempin;
int HEATERSTATE = 0;
char tbuf[64];

int BIASVOLTAGE = 0;
int HIGHVOLTAGE = 0;
float signalin = 0.;


#define HEATERREADS 2000 // should be in headerfile!
#define BIASREADS
#define HEATERONOFFPIN 13
#define HEATERON 1
#define HEATEROFF 0
#define D14PINREADING 2533     // reading from analogRead (reading above, from screen)
#define D14MEASUREDVOLTAGE 2.20 // volts to ground (from fluke measured to ground)

int SETTEMP = 125;
#include "buttonmenu.h"
#include "SSD1306.h"
#include "FS.h"
#include "SPIFFS.h"
SSD1306  display(0x3C, 21, 22);
#include "Adafruit_ADS1015.h"
void  PrettyScreen(char *HV, char *BIAS, char *MESSAGE);
void  oledPrettyScreen(char *HV, char *BIAS, char *MESSAGE, int font, char *range, char *temp);
void ReadMembrane();
int readFile(fs::FS &fs, const char * path);
void writeFile(fs::FS & fs, const char * path, const char * message);
void oled();
Adafruit_ADS1115 ads;  /* Use this for the 16-bit version */
void getUSD();
void CheckMode();
void LAMPMode();
void TEMPmode();
float AUTOZEROmode();
int counter2 = 0;
int lamp = 0; // 0 off  1 on
int persistantlamp = 0;
int persistantheat = 0;
#define FORMAT_SPIFFS_IF_FAILED true

int sensorV;
int a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, avg, temp;
int newoldlamp = 0, oldnewtemp = 0;
long counter = 0;
int modeval = 0;
int newtemp = 30;
int actualtemp = 123;
char button, oldbutton;
int state13 = 0;
int state12 = 0;
char pbuf[4096];
int sensorValue, sensorV2, sensorV3, sensorV4, sensorV5;
int sensorValue2;
int sensorValue3;;
int loopcount = 0;
int oldmodeval = 0;
int fileVal;
int range;

int readFile(fs::FS &fs, const char * path);


int state = 0;
int BUTTON = 0;
int OLDBUTTON = 0;
int OLDOLDBUTTON = 0;
int JUSTDELIVEREDBUTTON = 0;

int adc0, adc1, adc2, adc3, count = 0;



int a14, b14, c14, d14, e14, f14, temp14, temp14tmp, temp14tmp2;
int a12, b12, c12, d12, e12, f12, g12, h12, i12, j12, k12, l12, m12, n12, o12, p12, q12, r12, s12, t12, u12, hv12tmp, hv12;
int a2, b2, c2, d2, e2, f2, bias2, bias2tmp;
