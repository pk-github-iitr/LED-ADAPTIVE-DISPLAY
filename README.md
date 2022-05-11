# LED-ADAPTIVE-DISPLAY
Adaptive’s Full Color LED Displays to provide real-time information to people inside a single building or large building complex; communicating what to do in response to a threat.
Adaptive Communication displays relay critical alerts and messages automatically via highly visible, emergency full color LED signage as soon as an emergency or event is triggered - ensuring that all students, faculty or employees are aware of the crisis and know how to proceed to safety.  Our signage interfaces with most integrated systems.
We have used the concept of 7 segmented display i.e., we can reprsent any number in between 0-9 just by blinking some particular LEDs out of 7. In similar Passion, we can display any word on 8X8 LED matrix which is common cathode and common anode type ![8X8 LED Matrix](https://user-images.githubusercontent.com/105349056/167851126-9b31919c-983d-4fb6-90fc-5ba788e38616.jpeg)
To make our adaptive display long, we have utilise all the digital and analog pins of Arduino UNO, and we have design 5X15 LED matrix, which can show few characters of word altogether.
We have simulate this project on tinkercad and same thing we can do for the hardware https://www.tinkercad.com/things/eV4vtMEEEoD-swanky-waasa-jaagub/editel?sharecode=JIZNn5NyBxW8k8uTS8zIu8bKEg0yVnDOuavqIaRETMk

## MAKING_PROTOTYPE_OF_8X8 LED MATRIX
 First I have designed 8X8 LED MATRIX Display, which can display each letter of any word one by one https://www.tinkercad.com/things/8zGnrHuBV5a-byte-code/editel?sharecode=qXNX-9aTNwFb6FhO_bi6EhygnVYsJZjj8NBAWW9M86g.....In this display board we have shown a word "WELCOME TO IITR", in which each letter is dispalyed one by one and in between one letter to another we have put some randomeffects also.
 
 ## Materials Required For Hardware implementation
 1. LEDs: - As we need to make an 8X8 matrix, so we required 64 pieces of 5 mm LEDs in total.![image](https://user-images.githubusercontent.com/105349056/167856977-8813d8fe-1d9e-45b2-bba1-8a1ad0c0a33f.png)

2. Zero PCB Board: - For assembling the LEDs, Resistors, female headers, and Arduino UNO.![image](https://user-images.githubusercontent.com/105349056/167857188-a4ef778c-aa30-400e-908f-bd0986ff1b55.png)

3. 100-ohm Resistors : - That we will connect to the 8 common anodes of each column.![image](https://user-images.githubusercontent.com/105349056/167857525-f9e71edb-5c00-4438-a0d5-450ce53df7e9.png)

4. 2-Female headers: - Required to connect pins of Arduino with 8-common anodes and 8-common cathodes.![image](https://user-images.githubusercontent.com/105349056/167857860-1f56d6e8-fb5e-458d-93a5-1a45cafa9194.png)

5. Some connecting wires: - For connections.

7. Arduino Uno with cable: - The main brain of the circuit, operated when a code is uploaded using Arduino IDE software. ![image](https://user-images.githubusercontent.com/105349056/167857912-81f6cf28-8c8b-4a91-917d-96800a551cd9.png)

 ## Logic that we have used to represent any letter
 In the arduino code we have made arrays of all alphabets (A to z)
     Example for printing (T)
     byte A[] = {  
     B00000000,
     B00010000,
     B00101000,
     B01000100,
     B01000100,
     B01111100,
     B01000100,
     B01000100};

Converting each column into decimal 
     Byte A[] = {0,31, 36, 68, 36, 31,0,0};
## Showing each letter using the concept of Persistence of Vision
Millis() function is used for multitasking i.e., using this we can hold our previous ongoing task and can execute the next:-

void show( byte * image, unsigned long duration)
{
unsigned long start = millis(); 
while (start + duration > millis()) 
{
for(int row = 0; row < 8; row++)
{
digitalWrite(rowPins[row], HIGH); // connect row to +5 volts
for(int column = 0; column < 8; column++)
{
boolean pixel = bitRead(image[row],column);
if(pixel == 1)
{
digitalWrite(columnPins[column], LOW); // connect column to Gnd
}
delayMicroseconds(300); // **a small delay for each LED to move them fast such that it resembles a letter to human eye**
digitalWrite(columnPins[column], HIGH); // disconnect column from Gnd
}
digitalWrite(rowPins[row], LOW); // disconnect LEDs
}
}
}
## Conclusion
-> We have shown any word letter by letter on 8X8 LED Matrix. We have used the concept of a 7-segmented display i.e., how we can represent any number/word by turning on the particular LED.
-> For showing letters of any word, we have made arrays of each alphabet of the length of 8 representing every 8 columns, and each index represents the corresponding decimal value of an 8-bit binary number.
-> We have implemented this project on Tinkercad using Arduino Uno and also in Arduino code we have made use of the millis() function for executing multiple tasks at a time.

### CONRTIBUTORS
 <a href="https://github.com/pk-github-iitr">Peeyush Kumar</a><br/>


 






 
 

