#include <LiquidCrystal.h>
#define arr_len( x )  ( sizeof( x ) / sizeof( *x ) )

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
int i = 0; 

void setup() {

  Serial.begin(9600);

  lcd.begin(16, 2);     // set up the LCD's number of columns and rows
  int x = 0;
  int y = 0;
  i = 0;

  lcd.setCursor(x, y);

}

void loop() {
  char tape[] = {'B', 'B', '0', '0', '1', '1', 'B', 'B'} ;
  int tapeSize = arr_len (tape);

  lcd.print(tape[i]);
  Serial.print(tapeSize);
  Serial.print(',');
  Serial.print(i);
  Serial.print(',');
  Serial.println(tape[i]);

  if (i < tapeSize) {
    i++;
  }

  delay(3000);

  //  int state = 0;
  //    if (state = 0) {}
  //    if (state = 1) {}


}




//////////////////////////////////////////////////////////////////////////////
////////////////////////////FUNCTIONS/////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////






