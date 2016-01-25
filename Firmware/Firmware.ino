#include "Global.h"

#define THRESHOLD		100

int averageLight;

void setup() 
{
	Serial.begin(9600);
	Serial.println("start");
	
	motor.setMicroSteps(fullStep);
  
	//Get average light:
	averageLight = ldr.readAverage();

	//Print average light
	Serial.print("Average light:");
	Serial.println(averageLight); 
	
	delay(1000);
	Serial.println("start running");
	
}

void loop() 
{	
	int sample = ldr.read();
	int diff = abs(averageLight - sample);
	
	//print the difference
	Serial.print("Light: ");
	Serial.print(sample);
	Serial.print(", difference from average: "); 
	Serial.println(diff);
	
	//above threshold move servo:
	if(diff > THRESHOLD)
	{
		motor.write(1, 100, 2500);
		delay(500);
		motor.write(0, 100, 2500);
		delay(500);
	}

	delay(50);
  
}
