/*
  Interactivo
*/
String leido = "";

int pinArray[] = {2, 3, 4, 5, 6, 7};
int count = 0;
int timer = 100;

void setup() {
  
  for (count = 0; count < 6; count++) {
    pinMode(pinArray[count], OUTPUT);
  }
  Serial.begin(9600);
  Serial.println("Introduce la velocidad deseada: ");

}

void loop() {
 
  if (Serial.available() > 0) {
    leido = ""; //vacio lo leido
    do {
      char caracter_leido;
      delay(5);
      caracter_leido = Serial.read();
      leido += caracter_leido;
    }  while (Serial.available() > 0);

    Serial.println("He leido la cadena: \"" + leido + "\"");
   
    
    // convertir a int
    timer=String(leido).toInt();
 

  
  for (count = 0; count < 6; count++) {
    digitalWrite(pinArray[count], HIGH);
    delay(timer);
  }
  
  for (count = 0; count < 6; count++) {
    digitalWrite(pinArray[count], LOW);
    delay(timer);
  }
  
  for (count = 5; count >= 0; count--) {
   digitalWrite(pinArray[count], HIGH);
    delay(timer);
  }
  
  for (count = 5; count >= 0; count--) {
    digitalWrite(pinArray[count], LOW);
    delay(timer);
  }
  }
  
}
