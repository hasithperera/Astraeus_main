
// pin definitions and initialization functions
// basic IO functions are also added

#define Buzzer_pin 2

void init_io(){

  pinMode(Buzzer_pin,OUTPUT);


}


void beep(int delay_time){

  digitalWrite(Buzzer_pin,HIGH);
  delay(delay_time);
  digitalWrite(Buzzer_pin,LOW);
  delay(50);

}