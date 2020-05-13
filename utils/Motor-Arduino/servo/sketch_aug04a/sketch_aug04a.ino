#include <Servo.h>
String str = "Hello world!";
Servo servo;
int angle;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo.attach(3);
  servo.write(90);
  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:
     // Make servo go to 0 degrees 

  str = parseString();
  if(str == "") {
    return;
  }
  Serial.println(str);
  angle = str.toInt();
  servo.write(angle);
  
  //servo.write(50); 
  //delay(1000); 
  // Make servo go to 90 degrees 
  //servo.write(0); 
  //delay(1000); 
}

String parseString(){
  String str ;
  while(Serial.available()>0){
    str +=char(Serial.read());
    delay(2);
  }
  return str;
}
