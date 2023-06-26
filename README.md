# STM32-Music-Box
The box uses the STM32 Nucleo-64 F01RE Cortex M board and connectivity with a bread board.
It also uses an LED light and a very basic speaker capable of outputting simple notes.
This device does not take any user input but simply loops through the notes or music piece that are input into the code as long as the device is plugged in and running.

The project design is very small and simple, it uses just a simple breadboard and the supplied Nucleo board.
The speaker used for the board is not capable of much more than outputting simple frequencies from it which limits the amount that you can really do with it.
The light is a small LED light that can switch between red green and blue but can also appear a purplish color or a white if multiple colors are going all at once.
Jumper wires with “male to male” cable endings were used to connect the breadboard and the Nucleo Board.
Resistors were also used to regulate the flow of electric current within the circuit. 
The code that the project is using is very simple in its design and uses PWM output frequencies to the speaker,
as the notes with different timing set up for the different “beats” giving each note a different length it plays allowing for different tempos of music to be played.
It all runs through a while loop that repeats the music as long as it is plugged in and loaded onto the board. 

The code starts off by defining the different places that the components will be plugged in with D5, D6, and D9 hosting our red green and blue LED and D3 being where we have the speaker in.
D4 and D7 would be hosting the potentiometers if they would function. The notes are then defined with the frequency that they will output to the speaker,
ranging from C at 0.55 and reduces by about .1 to .05 for each note all the way down to CA at 0 which results in a sound pause.
The beat length is then defined with them ranging from .5 down to .075 for the length of a note. 
After this the notes that are to be played as well as the beat for each of the notes is put in as floats and there is a space for the music to be created.
The PWM for the speaker and the LEDs is then defined and then the ticker and a static variable of k which will be used later is defined. 
The ticker runs through an if loop in which if K is less than the size of the note/the size of the int it will then move forward to check if the note is CA that we previously mentioned was a sound pause.
If this is the case it changes the PWM duty cycle to 0. If it is not zero it will take the note that is called upon and multiply it by 0.005 and this will be the PWM that gets output and will determine the note that is heard by the user.
All of this runs on a while loop that keeps the code continuously repeating the music. 


Link to video of project running.
https://www.youtube.com/shorts/8uYtFZ29zSw
