#include <LiquidCrystal.h> //to use liquid crystal library.
LiquidCrystal lcd(13, 12, 11, 10, 9, 8); //Defines which pins of Arduino are to be connected to which pins of LCD display.
#define PIR_sensor 14 //variable declaration
#define m11 0//variable declaration
#define m12 1 //variable declaration
void setup() //Structure
{ 
	lcd.begin(20, 4); //Indicates no of columns and rows.
	pinMode(m11, OUTPUT); //set pin to output
	pinMode(m12, OUTPUT); //set pin to output
	pinMode(PIR_sensor, INPUT); //set pin to input
	lcd.print(" Automatic "); //display message
	lcd.setCursor(0,1); //set the cursor to column 0 and row 1
	lcd.print(" Door Opener "); //display message
	delay(3000); ///pause the program
	lcd.clear(); //clears the lcd screen
}
void loop() //loop function continuously executes the codes (i.e. reading inputs and triggering outputs)
{ 
	if(digitalRead(PIR_sensor)) //reads the value from specified digital pin with result either LOW or HIGH
	{ 
		lcd.setCursor(0,0); //set the cursor to top left corner
		lcd.print("Movement Detected"); //display message
		lcd.setCursor(0, 1); //set the cursor to bottom left corner
		lcd.print(" Gate Opened "); //display message
		digitalWrite(m11, HIGH);
		digitalWrite(m12, LOW); // gate opening
		delay(1000); //pause the program for 1 sec
		digitalWrite(m11, LOW);
		digitalWrite(m12, LOW); // gate stops
		delay(1000); //pause the program for 1 sec
		lcd.clear(); //clears the LCD screen
		lcd.print(" Gate Closed "); //display message
		digitalWrite(m11, LOW);
		digitalWrite(m12, HIGH); // gate closing
		delay(1000); //pause the program for 1 sec
		digitalWrite(m11, LOW);
		digitalWrite(m12, LOW); // gate closed
		delay(1000); //pause the program for 1 sec
	}
	else
	{
		lcd.setCursor(0,0); //set the cursor to top left corner
		lcd.print(" No Movement "); //display message
		lcd.setCursor(0,1); //set the cursor to bottom left corner
		lcd.print(" Gate Closed "); //display message
		digitalWrite(m11, LOW);
		digitalWrite(m12, LOW); //no movement of gate
	}
}