CMSC206_Final_Project
Generates Morse Code from keyboard input to LED light on breadboard from Raspberry Pi

Principle 
The idea of this project is to use threads to blink Morse code with an LED light that is connected to the Raspberry Pi.
The idea behind using threads was make it so the different LED lights could blink concurrently. It, although, seems to
not make much sense to run multiple LED lights when Morse code strives and needs to be comprehensible. For this fundamental
truth, I decided to use two LED lights with different threads that do not run at the same time, for the purpose of comprehensibleness.

Design 
This program has two layers of design: the hardware involved and the code itself. Starting with the hardware, for this project I used
two LED lights, two resistors, four wires, the breadboard, and the GPIO pegs on the Raspberry Pi. The wires were attached to the
GPIO pegs and connected to the breadboard. From the breadboard, the circuit continued to the LED light, through the resistor,
and back through the other wire. This setup was used for both individual LED lights. When writing the code, I initially hard-coded
each letter’s and number’s Morse code combination. After thought and consideration of suggestions in the presentation, I took out
the hard-code letter/number functions and left simply dot() and dash() functions. I wrote the threads in such a way that one was
linked to one LED light, and the other thread to the other light. I also used a string-compare function to exit the while-loop and
end the program. 
 
Implementation 
The program starts with using the necessary libraries, most notably, wiringPi.h and pthread.h, which make the execution of
the program possible. The variables defined for this program include the correct LedPin, a limit for the user command line input,
and the two strings: Dot and Dash. The GPIO pegs on the Raspberry Pi could be referenced within the code by finding the LedPin for
each peg; in this case, the LedPin numbers were 0 and 4. The next step was to write the dot and dash functions. In traditional
Morse code, dashes blink three times as long as dots, so I wrote the delay statements accordingly. The dot function turns on
the LED light for 300 milliseconds, and keeps it off for 300 milliseconds. The same applies for the dash function, except the
LED light (the other LED light) will be turned on for 900 milliseconds (three times as long as the dot’s light). Next, I created
two threads, one for each light and dot or dash. I used fgets() and a character array, cmdline, to prompt the user to enter a dot
or dash. The threads were called within conditional statements, using strcmp() to create the threads when a dot or dash was called
on the command line by standard input. The threads blinked the respective LED light for the correct duration to articulate Morse code
accurately. 
 
Evaluation 
The program worked as accurately as I had hoped when it was designed. One aspect that could have implemented, but never came to
fruition is to make it so the user would not have to press “Enter” to get the LED lights to blink—as in the user could just keep
typing dashes and dots and the LED lights would blink the desired combinations. Still, what is actually implemented works properly
and effectively.
