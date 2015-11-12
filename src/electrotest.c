/*
Filip Wallin, Oskar Hallbom, Anders Ruberg
Grupp 116
linUM lab 6 
*/
#include <stdio.h>
#include "libpower.h"
#include "libcomponent.h"
#include "libresistance.h"

int main()
{
	float volt, res;
	int component_count, x;
	char conn;
	// create arrays needed for resistance calcs


	printf("\nAnge spänningskälla i V: ");
	scanf("%f", &volt);
	printf("\nAnge koppling[S | P]: ");
	scanf("%c", &conn);
	printf("\nAntal komponenter: ");
	scanf("%i", &component_count);

	for (x = 1; x < component_count; x++)
	{
		printf("\n %iKomponent ", x ," i ohm: ");
		//Add value to array
	}

	printf("\nErsättningsresistans: "); //use function calc_resistance 
	printf("\nEffekt: %f", calc_power_r(volt,res));
	printf("\nErsättningsresistanser i E12-serien kopplade i serie: "); //use function e_resistance

	return 0;
}
