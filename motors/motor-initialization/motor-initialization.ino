
/*********************************************************************
 * Author: Patrick Rice
 * Date: 12/26/2017
 * Description: A test module for 4 motors.
*********************************************************************/

# include <Servo.h>

Servo m1, m2, m3, m4;
Servo motors[] = {m1, m2, m3, m4};
bool tested = false;


void setup() {
  Serial.begin(9600);

  Serial.println("Test initializing...");
  m1.attach(8);  //Specify here the pin number on which the signal pin of ESC is connected.
  m1.write(30);   //ESC arm command. ESCs won't start unless input speed is less during initialization.

  m2.attach(9);  
  m2.write(30);  

  m3.attach(10);  
  m3.write(30);   

  m4.attach(11);  
  m4.write(30);   

  delay(3000);            //ESC initialization delay.

}

void loop() {
  int speed;

  while(!tested){
    Serial.println("Test started");

    for(int i = 0; i < 4; i++){
      speed = 40;

      Serial.println("Motor " + String(i+1) + ": Started");

      while(speed < 100){
        motors[i].write(speed);    //Vary this between 40-130 to change the speed of motor. Higher value, higher speed.
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
