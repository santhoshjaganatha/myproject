// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int analogPin = A0;    
int val = 0;           // store the value read

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("What is the air ");
  lcd.setCursor(0, 1);
  lcd.print("quality today?");
  Serial.begin(9600);
  lcd.display();
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0,1);
  delay(100);
  val = analogRead(analogPin);     // read the input pin
  Serial.println(val);             // debug value
  lcd.clear();
  if (val >000 && val <= 306){
    lcd.print("Normal");
  } else if (val > 307 &&  val <= 420){
    lcd.print("Gas Detected");
  } else if (val > 421 && val <= 520){
    lcd.print("Dense Gas");
    lcd.setCursor(0, 1);
    lcd.print("Detected");
  } else if (val > 521 && val <= 724){
    lcd.print("EMERGENCY!");
  }
}
 