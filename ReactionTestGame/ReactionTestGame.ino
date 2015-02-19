const int starterLed = 2;
const int button1 = 5; 
const int button2 = 3;
const int led1 =  7;
const int led2 =  6;
long startTime = 0;
long reactionTime = 0;
boolean gameOver = false;
boolean gameStarted = false;

void setup() {
  pinMode(starterLed, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(button1, INPUT);     
  pinMode(button2, INPUT);
  Serial.begin(9600);
  startTime = millis();
}

void loop(){
  if (!gameOver)
  {  
    if (digitalRead(button1) == 0 && gameStarted) {    
      reactionTime = millis() - startTime;
      gameOver = true;
      digitalWrite(led1, HIGH);
      Serial.print("Player 1 wins - ");
      Serial.print(reactionTime);
      Serial.println();
      delay(2000);
      digitalWrite(led1, LOW);
    }
    
    if (digitalRead(button2) == 0 && gameStarted) {    
      reactionTime = millis() - startTime;
      gameOver = true;
      digitalWrite(led2, HIGH);
      Serial.print("Player 2 wins - ");
      Serial.print(reactionTime);
      Serial.println();
      delay(2000);
      digitalWrite(led2, LOW);
      
    }    
    
    while (millis() < 5000)
    {}
    
    gameStarted = true;
    digitalWrite(starterLed, HIGH); 
    
  }
}
