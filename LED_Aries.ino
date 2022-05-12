  
//LED ADAPTIVE DISPLAY

//Arrays of Word "WEL COME TO IITR" to display it on 5X15 LED Matrix
  byte WEL[]={ 0,31,2,4,2,31,0,31,21,17,0,31,1,1,0};
  byte COME[]={14,17,17,0,14,17,14,0,31,8,31,0,31,21,17};
  byte TO[]={ 0,0,16,16,31,16,16,0,0,14,17,17,14,0,0 };
  byte IITR[]={9,15,9,0,9,15,9,0,8,15,8,31,20,10,1};

//Arrays of each alphabets
  byte A[]= {0,31, 36, 68, 36, 31,0,0};//A
  byte B[]={0,127, 73, 73, 73, 54,0,0};//B
  byte C[]={0,62, 65, 65, 65, 34,0,0};//C
  byte D[]={0,127, 65, 65, 34, 28,0,0};//D
  byte E[]={0,127, 73, 73, 65, 65,0,0};//E
  byte F[]={0,127, 72, 72, 72, 64,0,0};//F
  byte G[]={0,62, 65, 65, 69, 38,0,0};//G
  byte H[]={0,127, 8, 8, 8, 127,0,0};//H
  byte I[]={0,65, 65, 127, 65, 65,0,0};//I
  byte J[]={0,2, 1, 1, 1, 126,0,0};//J
  byte K[]={0,127, 8, 20, 34, 65,0,0};//K
  byte L[]={0,127, 1, 1, 1, 1,0,0};//L
  byte M[]={0,127, 32, 16, 32, 127,0,0};//M
  byte N[]={0,127, 32, 16, 8, 127,0,0};//N
  byte O[]={0,62, 65, 65, 65, 62,0,0};//O
  byte P[]={0,127, 72, 72, 72, 48,0,0};//P
  byte Q[]={0,62, 65, 69, 66, 61,0,0};//Q
  byte R[]={0,127, 72, 76, 74, 49,0,0};//R
  byte S[]={0,50, 73, 73, 73, 38,0,0};//S
  byte T[]={0,64, 64, 127, 64, 64,0,0};//T
  byte U[]={0,126, 1, 1, 1, 126,0,0};//U
  byte V[]={0,124, 2, 1, 2, 124,0,0};//V
  byte W[]={0,126, 1, 6, 1, 126,0,0};//W
  byte X[]={0,99, 20, 8, 20, 99,0,0};//X
  byte Y[]={0,96, 16, 15, 16, 96,0,0};//Y
  byte Z[]={0,67, 69, 73, 81, 97,0,0};//Z
  

const int rowPins[] = {0,1,2, 3, 4, 5, 6,7,8,9,10,11,12,13,14};
const int columnPins[] = {19,18,17,16,15};

void setup() {
for (int i = 0; i < 15; i++)
{
pinMode(rowPins[i], OUTPUT);
}

for (int i = 0; i < 5; i++)
{
pinMode(columnPins[i], OUTPUT);
digitalWrite(columnPins[i], HIGH);
}
}

void loop()
{  
   delay(500);
   show(WEL,2000);
   show(COME,2000);
   show(TO,2000);
   show(IITR,2000);
}

void show( byte * image, unsigned long duration)
{
unsigned long start = millis();  //amount of time that we are going to wait
while (start + duration > millis()) 
{
for(int row = 0; row < 15; row++)
{
digitalWrite(rowPins[row], HIGH); // connect row to +5 volts
for(int column = 0; column < 5; column++)
{
boolean pixel = bitRead(image[row],column);
if(pixel == 1)
{
digitalWrite(columnPins[column], LOW); // connect column to Gnd
}
delayMicroseconds(300); // a small delay for each LED
digitalWrite(columnPins[column], HIGH); // disconnect column from Gnd
}
digitalWrite(rowPins[row], LOW); // disconnect LEDs of that row from +5 volts
}
}
}
