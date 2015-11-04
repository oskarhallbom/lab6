#include "libcomponent.h"


static float nominell_E12[E12_VALUES] = {1.00, 1.20, 1.50, 1.80, 2.20, 2.70,
                                         3.30, 3.90, 4.70, 5.60, 6.80, 8.20};

int e_resistance(float orig_resistance, float *res_array)
{
  int count = 0;
  float resistance_left = orig_resistance;
  float E12_value;

  while ((count < 3) && (resistance_left > 1.0))
  {
    E12_value = find_nearest_E12(resistance_left);
    if (res_array != NULL)
      res_array[count] = E12_value;

    resistance_left -= E12_value;
    count++;
  }

  return count;
}

float find_nearest_E12(float resistance)
{
  // Assume minimum resistant value given is 1.0 Ohm
  if (resistance < 1.0)
    return 0;
  
  const int pwr = power_of_ten(resistance);
  float E12_value;

  // Loop through E12 values, starting with the highest
  for (int i = E12_VALUES - 1; i >= 0; i--)
  {
    // Calulcate corresponding E12 value for this decade (tiotal)
    E12_value = nominell_E12[i] * pow(10, pwr);
    if ((fabs((double)(E12_value) - (resistance)) <= fabs((double)(GRANULARITY)))
        || (E12_value < resistance))
      break;
  }
  return E12_value;
}

int power_of_ten(float num)
{
    int power_of_ten = 0;
    while (num >= 1.0)
    {
        num /= 10;
        power_of_ten++;
    }
    return power_of_ten - 1;
}
