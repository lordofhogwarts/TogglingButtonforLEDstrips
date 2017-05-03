// Using a push button switch for stay-on/stay-off push button .
// beating a dead horse, again. Most of the real work is from other people.


int switch1 = 2; // connect a push button switch between this pin and ground
int switch2 = 10; 
int switch3 = 9;
int redPin = 5; // led pins 
int bluePin = 3;
int whitePin = 6;
int pumpPin = 13;
int count;        
boolean flag = true;
unsigned long previous = 0;
void setup()
{
  pinMode(redPin, OUTPUT); // this pin controlled by flipflop() function
  pinMode(whitePin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode (pumpPin, OUTPUT);
  pinMode (switch1, INPUT_PULLUP); 
  pinMode (switch2, INPUT_PULLUP);
  pinMode (switch3, INPUT_PULLUP);
  Serial.begin(9600); // just for debugging, not needed.
}

void loop()
{ int read1 = digitalRead(switch1); // reading the state of the buttons
  int read2 = digitalRead(switch2);
  int read3 = digitalRead(switch3);
  if ((read1 == HIGH && read2 == LOW) || (read1 == HIGH && read3 == LOW) || (read1 == HIGH && read2 == HIGH) || (read2 == HIGH && read3 == HIGH))
  // as long as switch 1 is pressed, do the below
  {

    delay(5);
    flipflop(switch1);
  }
  if ((read2 == HIGH && read1 == LOW) || (read2 == HIGH && read3 == LOW) || (read2 == HIGH && read1 == HIGH) || (read2 == HIGH && read3 == HIGH)) {

    Serial.print("state of switch 2 is "); Serial.println(read2);
    Serial.print("state of switch 3 is "); Serial.println (read3);
    delay(5);
    flipflop(switch2);
  }
  if ((read3 == HIGH && read1 == LOW) || (read3 == HIGH && read2 == LOW) || (read3 == HIGH && read1 == HIGH) || (read3 == HIGH && read2 == HIGH)){
    Serial.print("state of switch 3 is "); Serial.println (read3);
    Serial.print("state of switch 2 is "); Serial.println(read2);
    delay(5);
    flipflop(switch3);
  }

}// end of main loop.

void flipflop(int value) { //funtion flipflop
  flag = !flag;  // since we are here, the switch was pressed So FLIP the boolian "flag" state (we don't even care if switch was released yet)
  Serial.print("flag =   " );   Serial.println(flag);   // not needed, but may help to see what's happening.
  if (value == switch1) {
    if (flag == HIGH) { // Use the value of the flag var to change the state of the pin
      analogWrite(redPin, 175 );
      analogWrite(bluePin, 155); // if the flag var is HIGH turn the pin on
    }
    if (flag == LOW) { // if the flag var is LOW turn the pin off
      analogWrite(redPin, 0);
      analogWrite(bluePin, 0);
      analogWrite(whitePin,0);

    }
  }
  if (value == switch2) {
    if (flag == HIGH) { // Use the value of the flag var to change the state of the pin
      analogWrite(redPin, 255);
      analogWrite(bluePin, 137); // if the flag var is HIGH turn the pin on
      analogWrite(whitePin, 15);

 //           delay(1);
    }
    if (flag == LOW) { // if the flag var is LOW turn the pin off
      analogWrite(redPin, 0);
      analogWrite(bluePin, 0);
      analogWrite(whitePin,0);

    }
  }
//  if (value == switch3){
//  unsigned long currentMillis = millis();
//  unsigned long previousMillis1 = 0;        // will store last time LED was updated
//  long OnTime1 = 5000;           // milliseconds of on-time
//  long OffTime1 = 5000;          // milliseconds of off-time
//  Serial.println(currentMillis);
//  if((flag == LOW) && (currentMillis - previousMillis1 >= OnTime1))
//  {
//     // Turn it off
//    previousMillis1 = currentMillis;  // Remember the time
//    Serial.print("now is "); Serial.print(previousMillis1);
//    digitalWrite(pumpPin, LOW);  // Update the actual LED
//  }
//  else if ((flag == LOW) && (currentMillis - previousMillis1 >= OffTime1))
//  {  // turn it on
//    previousMillis1 = currentMillis;   // Remember the time
//    digitalWrite(pumpPin, LOW);    // Update the actual LED
//  }
//  }
  if (value == switch3){

    while (flag==HIGH){
      // Use the value of the flag var to change the state of the pin
      unsigned long current = millis();
      unsigned long twlhours = 1000*20*60;
      digitalWrite(pumpPin, HIGH);
      Serial.println(flag);
   //   delay(15000);
      Serial.println(current-previous); 
   //   Serial.print("prev is "); Serial.println(previous);
      Serial.print("current is "); Serial.println(current);
      digitalWrite(pumpPin, LOW);
   //   delay(00);
      Serial.print("count is "); Serial.println(count);
      if (current>30000){
        previous=current;
        break;
        }
   
    }
    
    if (flag == LOW) { // if the flag var is LOW turn the pin off
      digitalWrite(pumpPin, LOW);
  }
  }
  while (digitalRead(value) == HIGH); // for "slow" button release, keeps us in the function until button is UN-pressed
  // If you take out this "while" the function becomes a flipflop oscillator if the button is held down.
  delay(50); // OPTIONAL - play with this value.  It is probably short enough to not cause problems. deals with very quick switch press.*/
}


