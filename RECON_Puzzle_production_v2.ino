/*
 * Puzzle Production Code v2
 * 
 * This is code for the All-in-One Cabinet Mag Lock puzzle.
 * 
 * The tutorial for this puzzle was originally presented at RECON '21 during the "How to Build and Refine Your First Escape Room Tech Puzzle"
 * 
 * 
 * Created 2021
 * by Karmisha Jawell https://github.com/misha2ohh/
 * 
 * This example code is in the public domain.
 * 
 * https://github.com/misha2ohh/RECON21
 * 
 */

// Add this library, so we can talk to the MP3 player
#include <SoftwareSerial.h>

//Establish our own RX, TX pins instead of the default pins on the Uno (because we're using those for debugging)
SoftwareSerial mySerial(10, 11); // RX, TX

//define hall sensor
const int hallPin1 = 9; 
const int hallPin2 = 8; 
const int hallPin3 = 7; 
const int hallPin4 = 6; 

//variable for reading the state of each hall sensor
int hallState1 = 0;
int hallState2 = 0;
int hallState3 = 0;
int hallState4 = 0;

// Tells Arduino the relay is connected to pin 4
// The relay will power the maglock and LED strip
int relay = 4;


int startSFX = 0;

//Establish game states
// variables for the game states
// puzzleState = 0 > Not Solved
// puzzleState = 1 > Solved
int puzzleState = 0;

//// Establish puzzle states
//variables for the puzzle states
// gameOver = 0 > Keep running
// gameOver = 1 > Stop Running
int gameOver = 0;



void setup()
{
  //define hall sensor as inputs
  pinMode(hallPin1, INPUT_PULLUP);
  pinMode(hallPin2, INPUT_PULLUP);
  pinMode(hallPin3, INPUT_PULLUP);
  pinMode(hallPin4, INPUT_PULLUP);

  //define relay as an output
  pinMode(relay, OUTPUT);     


  // Open serial communications and wait for port to open:
  //So you can see what's happening using the Serial Monitor on your computer
  Serial.begin(9600);


  //Prints a message on the serial monitor to confirm it's working
  Serial.println("Serial is ready!");

  //This line has saved my tail 1000 times! Print out the name of the file currently running. 
  //Otherwise, you'll just have to guess! 
  Serial.println("File name: RECON_Puzzle_production_v2");

  //Set the data rate for the SoftwareSerial port used for communicating with the MP3 board
  mySerial.begin(9600);

}


void loop() // run over and over
{

 // tells Arduino what to do during the various game and puzzle states
  if (gameOver == 0) { //only run if the game isn't over
    
    if (puzzleState == 1) { //only run if the puzzle is completed
      endGame(); //reward players! This is a function that appears at the bottom of our code 
    
    } else if (puzzleState == 0) { //only run if the game isn't over and the puzzle isn't complete
      
      //only run if all hall sensors are triggered
      if (hallState1 == 0 && hallState2 == 0 && hallState3 == 0 && hallState4 == 0 ) { 
        //set the puzzle to complete if all pieces are present
        puzzleState = 1; 
      } 
       
    }
  }

}

//tells Arduino what to do when the puzzle has been solved and the game ends
void endGame() {

  revealPrize();
  playSound();
  
  //end the game by changing the game status
  gameOver = 1;
  
}

void revealPrize() {

  // Turn the relay on (HIGH is the voltage level = 1) 
  //// This will release the maglock and turn on the LED strip
  digitalWrite(relay, HIGH);   
  

}

void playSound() {
  

  //this will play the first track (001.mp3) on the board NOT SD card
  //// the instruction manual for this board is here: http://www.electronics123.net/amazon/datasheet/FN-BC04%20MP3%20Sound%20Module%20with%2010W%20Amplifier%20User's%20Manual%20V2.0.pdf
  mySerial.write(0x7E);
  mySerial.write(0xFF);
  mySerial.write(0x06);
  mySerial.write(0x03);
  mySerial.write((byte)0x00);
  mySerial.write((byte)0x00);
  mySerial.write(0x01);
  mySerial.write(0xEF);

  
}
