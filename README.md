# Design specs

This document contain the main design conditions for the program. 

## Pin requirement

|pin count| pins | usage | comment|
|---|---|---|---|
2 | A4,A5 | i2c | sensor data, acceleration and Pressure
4 |D13,D12,D11,D4| SPI | SD card. Tested with 5V. 
2 |A0,A1 | ADC |e_match detect(2 adc pins)
2 |D5,D6 |Digital out | main fets
1 |D2 |Digital out | Buzzer
2 |D9,D10 |second i2c | for APRS interface (optional)
2 |A6,A7 | D in | config 

## Seonsors and libraries used

- [ ] GY-521
- [x] MS5XX
- [ ] APRS slave

## Basic operation of a rocket

The following is based on comments from KC3RXZ
 
1. Power on
	1. branch sequence for recovery
		- make a serial interface to get/set data and save on the internal EEPROM.
	2. launch
		- print current config
2. Initialization wait period 
3. Calibrate sensors using average values from a 2 second interval to minimize bumps and wind and stuff
4. Wait to detect launch on gyro/pressure
5. Once pressure data starts to show increase(clarification) in height wait until we reach set height
6. Wait until we hit set height a second time and fire main after a set delay
7. After main wait to observe secondary height
8. Set delay and fire secondary


## progress 

### 05/26/23
- using the test PCB was able to get initial temp and pressure data. (have a working [library](https://github.com/abishur/ms5x) for the pressure sensor
- it was noted that a nano is capable of using the pressure sensor directly however the teensy 4.1 was not able to detect it. likely reason is the operation voltage levels. a level shifter is needed. But for easy testing moving the platform to a nano for the test cycle 
- SD card was tested. works with 5 V
- pin allocation and test platform developed.
- including tested libraries 20% program memory (reasonable).	
