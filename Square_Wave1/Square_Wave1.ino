/*
   R phase --------------- R phase(invert)---y phase --------------- y phase(invert)---B phase --------------- B phase(invert)
   OCR1A(-dead time)--------OCR1B-----------OCR2A(-dead time)--------OCR2B-----------OCR0A(-dead time)--------OCR0B
   digital 9----------------digital 10------digital 11--------------digital 3---------digital 6------------digital 5
   pb1-----------------------pb2-------------pb3-----------------------pd3-----------------pd6-------------------pd5

   button-----Arduino
   freq pos---D2(pd2)
   freq neg---D4(pd4)
   run--D12(pb4)
   stop--D8(pb0)
   indicator d13(high when run)
   relay signal d7
*/
#include<avr/io.h>
#include<avr/interrupt.h>
#include <util/delay.h>

double delay60degree; //60 degre delay
int deadtime = 150; //150us
double delayWithoutDead;
int Debounce_delay=80;//80ms
unsigned long t=0;


#define DATA1 PC0 // A0 -> PC0//ds
#define LATCH1 PC1 // A1 -> PC1//stcp
#define CLOCK1 PC2 // A2 -> PC2//shcp

#define DATA0 PC3 // A3 -> PC3//ds
#define LATCH0 PC4 // A4 -> PC4//stcp
#define CLOCK0 PC5 // A5 -> PC5//shcp

int freq_f = 50;
byte max_freq = 99, min_freq = 10;
float old_freq;
bool usedCT=false, run_inverter = true, displayF=true,run_inverterPress=false,maxCurrentPass=false;
float current;
byte maxCurrent=6;//maximum allow
unsigned long CT_time;
void setup() {
  pinconfig();
  setPinsLow();
  adjust_freq();
  ext_int_init();
  PORTD |= (1 << PORTD7); // initialy high relay
  //PORTD &= ~(1 << PORTD7); // initialy low relay
  if (run_inverter == true) PORTB |= (1 << PORTB5);
}
void loop(){
    if (run_inverter == true) square();
    else {
      setPinsLow();
      currentMeasure();
    }
}
