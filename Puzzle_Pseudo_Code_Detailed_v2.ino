/*
 * Puzzle Pseudo Code Detailed v2
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

//Pull in libraries and set variables here 

Include software serial library so the Arduino and MP3 board can talk

Define hall sensors 

Create variables to store readings from hall sensors

// For testing purposes only, not needed for the puzzle)
Define LEDs

Create variable Initiate SFX

Create variable to store the puzzle state
//There are 2 states: Solved and Not Solved

Define the relay

void setup() {
// put your setup code here, to run once:
  
// Establish inputs and outputs
Set up hall sensors as inputs

Set up the LEDs as outputs

Set up the relay as an output

Start Serial communications
   Then print message saying serial communications are ready
   Then print message containing the file name

Start Software Serial communications

 

}

void loop() {
  // put your main code here, to run repeatedly:
  // This is where the action happens!

  Read each hall sensor 
     Store the data in a variable
     Print the new value of that variable
 
  Setup IF statements to turn on LEDs
     If a hall sensor detects a magnet
        THEN turn on its respective LED

  Setup IF statement to determine if puzzle has been solved
     If all hall sensors are detecting a magnet
        THEN change the puzzle state to solved

}

//Setup functions here
Write a function to run a sequence of events once the puzzle is solved

Write function to release mag lock...and turn on LED strip

Write function to tell the MP3 board to play the sound
