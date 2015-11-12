/*
Filip Wallin
1989-10-27-7519
linUM lab 6
Grupp 116, Oskar Hällblom, Anders Ruberg, Filip Wallin 
2015-11-02
*/

#include <stdio.h>

/*Calculates P=U^2/R and returns the result as float*/
float calc_power_r(float volt, float resistance)
{
	float p = volt*volt/resistance;
	return p;
}

/*Calculates P=U*I and returns the result as float*/
float calc_power_i(float volt, float current)
{
	float p = volt*current;
	return p;
}
