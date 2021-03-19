/**********************************************************                                                                        
                Defining the Liquid Crystal Display 
                       and Other Variables
**********************************************************/
#include <LiquidCrystal.h> //include LCD library

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

long microSecs;
float freq;
int lastBit;
int nowVal;
long secs;
long maxHz;
long minHz;
long minmax;
/***********************************************
               Setting Up Pins 
***********************************************/
void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Loading...");
  pinMode(A0,INPUT); //set A0 as input
  pinMode(A5,OUTPUT); //set A5 as the output
  microSecs = micros();
  freq = 0;
  lastBit = 0;
  nowVal =0;
  maxHz=0;
  minHz=0;
  minmax=0;
  secs = millis();
  //Serial.begin(9600);
}
int x=0;

void loop() {


  if ((microSecs+20)<micros()){
      nowVal=digitalRead(A0);
 
      if (lastBit!=nowVal) {
        lastBit=nowVal;
        freq=freq+1;
      }
      if (freq>maxHz){
        maxHz=freq;
      }
      if (freq<minHz){
        minHz=freq;
      }
     
      microSecs = micros();
  }
  if (secs+1000<millis()){

    if (minmax+300000<millis())
    {
      minmax=millis();
      minHz=freq;
      maxHz=freq;
      
    }
      
      lcd.clear();
      lcd.print("FREQ. : ");
      lcd.print((freq/2));
      lcd.print("hz");
 
      
      freq=0;
      secs=millis();
      
  }
}