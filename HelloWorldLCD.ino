// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7,8,9,10,11,12);

void setup() {
  lcd.begin(16, 2);     // set up the LCD's number of columns and rows:
  

}

void loop() {

  char a = 'B'; 
  char b = 'B'; 
  char c = 'B'; 
  char d = 'B'; 
  char e = 'B'; 
  char f = 'B'; 
  char g = 'B'; 
  char h = 'B'; 
  char i = 'B'; 
  char j = 'B'; 
  char k = 'B'; 
  char l = 'B'; 
  char m = 'B'; 
  char n = 'B'; 
  char o = 'B'; 
  char p = 'B'; 
  
  lcd.print(a);
  lcd.print(b);
  lcd.print(c);
  lcd.print(d);
  lcd.print(e);
  lcd.print(f);
  lcd.print(g);
  lcd.print(h);
  lcd.print(i);
  lcd.print(j);
  lcd.print(k);
  lcd.print(l);
  lcd.print(m);
  lcd.print(n);
  lcd.print(o);
  lcd.print(p);

  
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
}

