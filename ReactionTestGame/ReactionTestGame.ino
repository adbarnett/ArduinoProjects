#define starterLed 2
#define button1 5 
#define button2 3
#define led1 7
#define led2 6

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
  
}

void loop(){
  if (!gameOver)
  {     
    if (!gameStarted)
    {
      while (millis() < 5000 && !gameOver)
      {
        if (digitalRead(button1) == 0) {
          digitalWrite(led2, HIGH);
          Serial.print("Player 2 wins. Player 1 pressed too soon");
          Serial.println();
          delay(2000);
          digitalWrite(led2, LOW);
          gameOver = true;
          Serial.println("Game Over");
          Serial.println("Press reset");
        }
      
        if (digitalRead(button2) == 0) {
          digitalWrite(led1, HIGH);
          Serial.print("Player 1 wins. Player 2 pressed too soon");
          Serial.println();
          gameOver = true;
          delay(2000);
          digitalWrite(led1, LOW);
          Serial.println("Game Over");
          Serial.println("Press reset");
        }
      }
    
      if (!gameOver)
      {
        gameStarted = true;
        startTime = millis();
        digitalWrite(starterLed, HIGH);
      }
      else
      {
 
      }
    }
    
    if (digitalRead(button1) == 0 && gameStarted) {
        reactionTime =  millis() - startTime;
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
   
  }
  else
  {
    delay(20000);
    digitalWrite(starterLed, LOW);
    Serial.println("Game Over");
    Serial.println("Press reset");
  }
}
