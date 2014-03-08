/*
power calculation functions by Klaus Virtanen
calculates power based on either voltage & la resistance
or voltage & current


*/

#include <stdio.h>


float calc_power_r(float volt, float resistance)
{
	//this should not happen
	if(resistance==0)
	{
		return -1;
	
	}
	else
	{
	
		float power = volt*volt/resistance;
		
		return power;
	}
}

float calc_power_i(float volt, float current)
{
	float power = volt * current;
	
	return power;
}
