int i = 0; 
int j = 0; 
int dir = 0; 
int a = 0; 

char tape[18][18] = {    // creates the blank, two dimensional tape
                {'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B'} ,  
                {'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B'} ,
                {'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B'} ,
                {'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B'} ,
                {'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B'} ,
                {'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B'} ,
                {'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B'} ,
                {'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B'} ,
                {'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B'} ,
                {'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B'} ,
                {'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B'} ,
                {'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B'} ,
                {'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B'} ,
                {'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B'} ,
                {'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B'} ,
                {'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B'} ,
                {'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B'} ,
                {'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B'}                              
                } ;


void setup() {
  Serial.begin(9600);

  i = 9;          // sets the starting position of the ant 
  j = 9; 
  printarray();   //prints the initial, plank array 

}

void loop() {

  if (tape[i][j] == 'B'){                                  // if the square with the ant is a B 
    Serial.println("--------- It was a B ----------");     // output this to remind what square it was
    tape[i][j] = '1';    // update the state and spot      // change that square to a 1
    right();                                               // turn the ant to the right
    moveit();                                              // move the ant to the next spot
    printarray();                                          // print the new, edited tape
     
  }


  if ( tape[i][j] == '1'){                                 // if the square with the ant is a a
    Serial.println("--------- It was a 1 ----------");     // output this to remind what square it was
    tape[i][j] = 'B';                                      // change that square to a B
    left();                                                // turn the ant to the left
    moveit();                                              // move the ant to the next spot
    printarray();                                          // print the new, edited tape
  }
   
}


/////////////////////////////////////////////////////////////////////////
////////////////////////////FUNCTIONS////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

void printarray(){
  for ( int j = 0; j < 18 ; j++){              // iterates through the x direction
     for ( int i = 0; i < 18 ; i++){           // iterates through the y direction
       if (i == 17){
         Serial.println(tape[i][j]);           // newline if you get to the end of a line
       }
       else{
        Serial.print(tape[i][j]);              // print the relevant character 
       }
    }
  }

  a++; 
  Serial.print("---------- Turn# : ");       // count what turn you are on 
  Serial.print(a); 
  Serial.println(" ----------");
}


void right(){                               // increase the direction by 1, going clockwise
  dir++ ; 
}

void left(){                                // increase the direction by 3, effectively going counterclockwise 
  dir++ ; 
  dir++ ; 
  dir++ ; 
}

void moveit(){                              // mod 4 in case your direction swung all the way around 
  dir = dir % 4; 
  if (dir == 0){ j++ ; }    //up
  if (dir == 1){ i++ ; }    //right
  if (dir == 2){ j-- ; }    //down
  if (dir == 3){ i-- ; }     //left
}



