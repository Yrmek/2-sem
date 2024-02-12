#include <iostream>
#include "header.h"
#include <math.h>

double myfunc(double x, double s, double t)
{
	return (t * 3 * pow(x, s) / pow(1 + pow(x, 3), 0.5));
}

void main()
{
	double s1 = 1, s2 = 4, delta_s = 1, // [1 ; 4] delta s = 1
		t1 = 0.2, t2 = 1.2, delta_t = 0.2,// [0.2 ; 1.2] delta t = 0.2 
		a = 0,
		b = 1.075,
		r = 1e-6,    //eps
		integral = 0;
	int k_iter = 0;
	for (s1; s1 <= s2; s1 += delta_s)
	{
		t1 = 0.2;
		for (t1; t1 <= t2; t1 += delta_t)
		{
			integral = calc_integral(a, b, s1, t1, r, myfunc, k_iter);
			print_integral(s1, t1, integral, k_iter);
		}
	}
}