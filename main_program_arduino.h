//references
//https://www.arduino.cc/reference/en/language/functions/time/delay/
//https://www.arduino.cc/reference/en/language/structure/control-structure/for/
//https://www.arduino.cc/en/Tutorial/Button
//https://circuitdigest.com/microcontroller-projects/arduino-uno-adc-tutorial
//http://www.circuitbasics.com/how-to-set-up-an-lcd-display-on-an-arduino/
//Gregory Chernov
//main_program_arduino
//Just some test code to figure out some functions in the arduino for our project and see how they work together
//Need to come up with better way to handle button input not using a delay
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

char ADCSHOW[5]; //initializing a character of size 5 for showing the ADC result
const int buttonPin = 39;
int buttonState = 0; 
int overTwo = 0;
void setup()

{
  pinMode(buttonPin, INPUT);
  // set up the LCD's number of columns and rows:

  lcd.begin(16, 2);

}

void loop(){
buttonState = digitalRead(buttonPin);
if (buttonState == HIGH) {
   overTwo = overTwo+1;
   delay(500);
  }
if (overTwo%2 == 1) {
      xaxis();
    }
    else{
      yaxis();
    }
}



void xaxis()

{
  // set the cursor to column 0, line 1
  
  lcd.print("X-AXIS"); //print name

  lcd.setCursor(0, 1); // set the cursor to column 0, line

  lcd.print("ADC RESULT:"); //print name

  String ADCVALUE = String(analogRead(A0)); //intailizing a string and storing ADC value in it 

  ADCVALUE.toCharArray(ADCSHOW, 5); // convert the reading to a char array 

  lcd.print(ADCSHOW); //showing character of ADCSHOW

    lcd.print("   ");

  lcd.setCursor(0, 0); // set the cursor to column 0, line1

}

void yaxis(){

    lcd.print("Y-AXIS"); //print name

    lcd.setCursor(0, 1); // set the cursor to column 0, line

    lcd.print("ADC RESULT:"); //print name

    String ADCVALUE = String(analogRead(A1)); //intailizing a string and storing ADC value in it 

    ADCVALUE.toCharArray(ADCSHOW, 5); // convert the reading to a char array 

    lcd.print(ADCSHOW); //showing character of ADCSHOW

      lcd.print("   ");

    lcd.setCursor(0, 0); // set the cursor to column 0, line1
  

}