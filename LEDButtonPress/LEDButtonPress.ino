const int button = 5; 
const int led =  7;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);     
}

void loop(){

  if (digitalRead(button) == 0) {    
    digitalWrite(led, HIGH);  
  } 
  else {
    digitalWrite(led, LOW); 
  }
}
