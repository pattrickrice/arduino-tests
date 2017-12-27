/*********************************************************************
 * Author: Patrick Rice
 * Date: 12/26/2017
 * Description: A test module for 4 motors.
*********************************************************************/

# include <Servo.h>

Servo m1, m2, m3, m4;
Servo motors[] = {m1, m2, m3, m4};
bool tested = false;



/*********************************************************************
 * Initialize the motors 
*********************************************************************/
void setup() {
  Serial.begin(9600);

  Serial.println("Test initializing...");
  m1.attach(8);   // Specifies the  pin number on which the signal pin of ESC is connected.
  m1.write(30);   // ESC arm command. ESCs won't start unless input speed is less during initialization.

  m2.attach(9);  
  m2.write(30);  

  m3.attach(10);  
  m3.write(30);   

  m4.attach(11);  
  m4.write(30);   

  delay(3000);    // ESC initialization delay.

}

/*********************************************************************
 * Loop through all of the motors, turn slowly increase their speed.
 * The goal of the test here is to make sure the escs are receiving 
 * the input and the motors are reacting properly.  
*********************************************************************/
void loop() {
  int speed;

  while(!tested){
    Serial.println("Test started");

    for(int i = 0; i < 4; i++){
      speed = 40;

      Serial.println("Motor " + String(i+1) + ": Started");
      
      // speed can vary between 40-130, the higher the value, the 
      // higher the speed.
      while(speed < 100){
        motors[i].write(speed);   
        delay(1500);
        speed += 10;
      }
      motors[i].write(0);
      Serial.println("Motor " + String(i+1) + ": Finished");
      
    }

    Serial.println("Test Complete");
    tested = true;

  }
}
