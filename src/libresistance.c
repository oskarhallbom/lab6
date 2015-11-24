
/*
Oskar Hällbom
19881224-1936
Grupp 116
2015-11-24
linum labb 6
*/


#include <stdio.h>
 

float calc_resistance(int count, char conn, float *arrayIn)
{
	double sumResistance = 0;
	printf("Hello world2\n");
	/*Checks that count is greater than 0.
	  Checks that the array is not a nullpointer*/
	if(count < 0 | arrayIn == 0)
	{
		printf("error\n");
		return -1;
	}
	printf("Hello world3\n");
	/*Calculates resistance if the components are in parallel.*/
	if(conn == 'P')
	{
		int x;
		for (x = 0; x< count; x++)
		{
			if(arrayIn[x] == 0)
			{
				return 0;	
			}
			sumResistance += (1/arrayIn[x]);
		}
		return sumResistance;
	}

	/*Calculates resistance if the components are in a series*/
	else if(conn == 'S'){
		int x;
		for (x = 0; x< count; x++){
			sumResistance += arrayIn[x];
		}
		return sumResistance;
	}
	else{
	return -1;
	}

}
