

// MS5  - Pressure and temp data update
/* This will set oversampling ratio, acceptable values are:
	   MS5xxx_CMD_ADC_256 (Resolution RMS Temp=0.012°C/Press=0.065mbar)
	   MS5xxx_CMD_ADC_512 (Resolution RMS Temp=0.008°C/Press=0.042mbar)
	   MS5xxx_CMD_ADC_1024 (Resolution RMS Temp=0.005°C/Press=0.027mbar)
	   MS5xxx_CMD_ADC_2048 (Resolution RMS Temp=0.003°C/Press=0.018mbar)
	   MS5xxx_CMD_ADC_4096 (Resolution RMS Temp=0.002°C/Press=0.012mbar) <- Default
	*/

void init_BMP() {
  barometer.setI2Caddr(I2C_HIGH);
  barometer.setSamples(MS5xxx_CMD_ADC_256);
  barometer.setDelay(2); 

  // need to be set experimentally - not corrected (05/24/23)
  //barometer.setTOffset(-200); // Decreases temperature reading by 2.00°C
  //barometer.setPOffset(5); // Increases pressure reading by 5 Pascals

}

int connect_BMP(){
  return barometer.connect();
}

int update_pressure() {

  	barometer.checkUpdates();
		if (barometer.isReady()) { 
      pressure = barometer.GetPres();
      // Returns pressure in selected units
      return 0;
    } 
    return 1;
}


// accelerometer