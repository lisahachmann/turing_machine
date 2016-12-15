#include <LiquidCrystal.h>
#define arr_len( x )  ( sizeof( x ) / sizeof( *x ) )

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
int i = 0;
int state = 0;

char tape[] = {'B', 'B', '0', '1', '0', '1', 'B', 'B'} ;      // create the tape 


void setup() {

  Serial.begin(9600);
  lcd.begin(16, 2);     // set up the LCD's number of columns and rows

  int x = 0; 
  int y = 0;
  i = 0;
  state = 0;

  int tapeSize = arr_len (tape) ;

  lcd.setCursor(x, y);
  lcd.print(tape);                                    // display the tape

  while (tape[i] == 'B') {                            // move the reader to the first non-blank spot
    i++;
  }
}

void loop() {

  if (state == 0 && tape[i] == '0') {               // tuple 1: (s0, 0, s1, 0, R)
    printarrow();     // show the arrow for the character we are reading 
    delay(1000);
    state = 1;        // reset the state to 1
    tape[i] = '0';    // update the state and spot
    printtape();      // print the updated tape
    cleararrow();     // clear the old arrow location
    i++;              // move right
    printarrow();     // print the new arrow location
    delay(3000);
  }

  if (state == 0 && tape[i] == '1') {               // tuple 2: (s0, 1, s1, 0, L)
    printarrow();
    delay(1000);
    state = 1;
    tape[i] = '0';    // update the state and spot
    printtape();
    cleararrow();
    i--;
    printarrow();
    delay(3000);
  }

  if (state == 0 && tape[i] == 'B') {               // tuple 3: (s0, B, s1, 1, R)
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

  if (state == 1 && tape[i] == '0') {               // tuple 4: (s1, 0, s2, 1, R)
    printarrow();
    delay(1000);
    state = 2;
    tape[i] = '1';    // update the state and spot
    printtape();
    cleararrow();
    i++;
    printarrow();
    delay(3000);
  }

  if (state == 1 && tape[i] == '1') {               // tuple 5: (s1, 1, s1, 1, R)
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

  if (state == 1 && tape[i] == 'B') {               // tuple 6: (s1, B, s2, 0, R)
    printarrow();
    delay(1000);
    state = 2;
    tape[i] = '0';    // update the state and spot
    printtape();
    cleararrow();
    i++;
    printarrow();
    delay(3000);
  }

  if (state == 2 && tape[i] == 'B') {               // tuple 7: (s2, B, s3, 0, R)
    printarrow();
    delay(1000);
    state = 3;
    tape[i] = '0';    // update the state and spot
    printtape();
    cleararrow();
    i++;
    printarrow();
    delay(3000);
  }
}

/////////////////////////////////////////////////////////////////////////
////////////////////////////FUNCTIONS////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

void printarrow() {
  lcd.setCursor(i, 1);    // the second row, in the i-th column
  lcd.print("^");         // where the reader is
}

void cleararrow() {       // overwrite the old arrow since the reader is moving 
  lcd.setCursor(i, 1);
  lcd.print(' ');
}

void printtape() {        // print the new tape 
  lcd.setCursor(0, 0);
  lcd.print(tape);  
  delay(1500);  
}
