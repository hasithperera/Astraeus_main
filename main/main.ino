
#include <Wire.h>
#include <MS5x.h>

#include <SPI.h>
#include <SD.h>

MS5x barometer(&Wire);
double pressure = 0;
long cnt_p = 0;
long ms_cnt = 0;
double tmp[50];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  init_io();
  delay(100);

  Serial.println("WVU ERC - Ast mainboard");

  beep(10);
  beep(10);

  init_BMP();
  delay(10);
  int cnt = 0;
  while (connect_BMP() > 0) {  // barometer.connect starts wire and attempts to connect to sensor
    cnt++;
    delay(2);
  }
  Serial.println("p1");
}

void loop() {
  // put your main code here, to run repeatedly:
  
  ms_cnt = millis();
  if (ms_cnt<700 & ms_cnt>500) {
    update_pressure();
    tmp[cnt_p++]=pressure;
    //Serial.println(update_pressure());
    //Serial.println(pressure);
    delay(10);
  }
  if (millis()>1000 & millis()<1002)
    for(int i=0;i<cnt_p;i++){
    Serial.print(i);
    Serial.print(" ");
    Serial.println(tmp[i]);
    }

  
}
