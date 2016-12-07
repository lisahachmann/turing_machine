#include <LiquidCrystal.h>
#define arr_len( x )  ( sizeof( x ) / sizeof( *x ) )

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
int i = 0; 
int state = 0; 

char tape[] = {'B', 'B', '0', '0', '1', '1', 'B', 'B'} ;

  
void setup() {

  Serial.begin(9600);
  lcd.begin(16, 2);     // set up the LCD's number of columns and rows

  int x = 0;
  int y = 0;
  i = 0;
  state = 0; 

  int tapeSize = arr_len (tape) ;

  lcd.setCursor(x, y);
  lcd.print(tape); 

  while (tape[i] == 'B'){
    i++; 
  }
}

void loop() {



  if (state == 0 && tape[i] == '0'){
    Serial.print("tuple 1");
    printarrow(); 
    delay(1000); 
    state = 1;
    tape[i] = '1';    // update the state and spot
    printtape(); 
    cleararrow(); 
    i++; 
    printarrow(); 
    delay(3000);
  }

  if (state == 0 && tape[i] == '1'){
    Serial.print("tuple 2");
    printarrow(); 
    delay(1000); 
    state = 1;
    tape[i] = '0';    // update the state and spot
    printtape(); 
    cleararrow(); 
    i++; 
    printarrow(); 
    delay(3000);
  }  
  
if (state == 0 && tape[i] == 'B'){
    Serial.print("tuple 3");
    printarrow(); 
    delay(1000); 
    state = 1;
    tape[i] = '0';    // update the state and spot
    printtape(); 
    cleararrow(); 
    i++; 
    printarrow(); 
    delay(3000);
  }  
  
if (state == 1 && tape[i] == '0'){
    Serial.print("tuple 4");
    printarrow(); 
    delay(1000); 
    state = 2;
    tape[i] = '1';    // update the state and spot
    printtape(); 
    cleararrow(); 
    i--; 
    printarrow(); 
    delay(3000);
  }  
  
if (state == 1 && tape[i] == '1'){
    Serial.print("tuple 5");
    printarrow(); 
    delay(1000); 
    state = 1;
    tape[i] = '0';    // update the state and spot
    printtape(); 
    cleararrow(); 
    i++; 
    printarrow(); 
    delay(3000);
  }  
  
if (state == 1 && tape[i] == 'B'){
    Serial.print("tuple 6");
    printarrow(); 
    delay(1000); 
    state = 2;
    tape[i] = '0';    // update the state and spot
    printtape(); 
    cleararrow(); 
    i--; 
    printarrow(); 
    delay(3000);
  }
   
}


/////////////////////////////////////////////////////////////////////////
////////////////////////////FUNCTIONS////////////////////////////////////
/////////////////////////////////////////////////////////////////////////


void printarrow(){
  lcd.setCursor(i,1); 
  lcd.print("^"); // where the reader is 
}

void cleararrow(){
   lcd.setCursor(i,1); 
   lcd.print(' ');
}

void printtape(){
  lcd.setCursor(0,0); 
  lcd.print(tape);   // print the new tape 
}

