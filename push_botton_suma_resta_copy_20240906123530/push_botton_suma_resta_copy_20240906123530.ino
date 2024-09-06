int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
int led5 = 6;
int led6 = 7;
bool estado_boton1;
bool estado_boton2; 
bool estado_led1 = 0;
bool estado_led2 = 0;
bool estado_led3 = 0;
bool estado_led4 = 0;
bool estado_led5 = 0;
bool estado_led6 = 0;
int leds_on = 1;

void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  for(int i=2; i<8; i++){
    pinMode(i,OUTPUT);
  }
}

void loop() {
  estado_boton1 = digitalRead(A0);    //asigna el estado del boton1 al valor A0
  estado_boton2 = digitalRead(A1);    //asigna el estado del boton2 al valor A1
  for(int i=2; i<8; i++){
    leds_on = digitalRead(i);
  }
  //para encender el led1
  if(leds_on == 2){
    if(estado_boton1 == 1){     //si se presiona el boton 1 
      digitalWrite(led1,1);     //enciende el led1
      delay(50);                  //delay para evitar rebotes
      estado_led1 = !estado_led1;     //cambia el estado del led1 a encendido
    }
    if(estado_boton2 == 1 && estado_led1){    //si se presiona el boton2 y el led1 esta encendido 
      digitalWrite(led1,0);             //apaga el led1  
    }
  }  

  if(leds_on == 3){
    if(estado_boton1 == 1){
      digitalWrite(led2,1);
      delay(50);
      estado_led2 = !estado_led2;
    }
    if(estado_boton2 == 1 && estado_led2){
      digitalWrite(led2,0);
    }
  }
}

