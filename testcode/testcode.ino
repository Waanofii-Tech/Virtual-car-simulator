//led ls rs bl  r f n   to rs ls bs 
//     6 5  3,4 7, 8, 9 13  10 11 12
float steer;
float brake;
float acceleration;
String gear="n";
String all="";
//done
void setup() {
  // put your setup code here, to run once:
  Serial.begin(19200);
  for (int i=3;i<7;i++){
    pinMode(i,OUTPUT);
    }
  for (int j=7; j<14; j++){
    pinMode(j,INPUT);
  }
  pinMode(A0, INPUT); //steer input
  pinMode(A1, INPUT); //brake input
  pinMode(A2, INPUT); //acceleration
}

void loop() {
  // switch for all circuit.
  
    if (digitalRead(13)){
      
      //left side
      if (digitalRead(11)){
        while(digitalRead(11)){
          digitalWrite(6, HIGH);
          delay(500);
          digitalWrite(6, LOW);
          delay(500);
        }
      }
      else if (!digitalRead(11)) {
        digitalWrite(6, LOW);
      }
      
      //right side
      if (digitalRead(10)){
        while(digitalRead(10)){
          digitalWrite(5, HIGH);
          delay(500);
          digitalWrite(5, LOW);
          delay(500);
        }
        
      }
      else if (!digitalRead(10)) {
        digitalWrite(5, LOW);
      }
      
      //hazard light
      if (digitalRead(12)){
        while(digitalRead(12)){
          digitalWrite(5, HIGH);
          digitalWrite(6, HIGH);
          delay(500);
          digitalWrite(5, LOW);
          digitalWrite(6, LOW);
          delay(500);
        }
      }
      else if (!digitalRead(12)) {
        digitalWrite(5, LOW);
        digitalWrite(6, LOW);
      }
      //reverse/forward/neutral
      if (digitalRead(7)){
//        Serial.println("r");
        gear = "r";
      }
      if (digitalRead(8)) {
//        Serial.println("f");
        gear = "f";
      }
      if(digitalRead(9)){
//        Serial.println("n");
        gear = "n";
      }
      delay(20);
      
      //steer
      steer = map(analogRead(A0), 0,1023, -100,100);
//      Serial.println(steer);
      delay(20);
      
      //acceleration
      acceleration = map(analogRead(A1), 0,1023, 0,100);
//      Serial.println(accelaration);
      delay(20);
      
      //brake
      brake = map(analogRead(A2), 0,1023, 0,100);
//      Serial.print(brake);
      delay(200);
      all+=gear;
      all+=",";
      all+=int(acceleration);
      all+=",";
      all+=int(steer);
      all+=",";
      all+=int(brake);
      Serial.println(all);
      steer, acceleration, brake = 0;
  }
  else {
    Serial.println("engine off");
    all="";
    delay(20);
  }
  all="";
  delay(30);
}
