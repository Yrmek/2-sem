#pragma once
#include <iomanip>
#include <iostream>

using namespace std;

double calc_integral_via_trapeze(double a, double b,double s, double t,double r, double (*myfunc)(double, double, double), int & k_iter)
{
	double integ_n = 0, integ_2n = 0, h = 0 , x = a, sum = 0;
	int n = 1;
	k_iter = 0;
	do
	{
		integ_n = integ_2n;
		n++;
		h = (b - a) / n;
		x = a;
		for (int i = 1; i <= n - 1; i++)
		{
			x += h;
			sum += myfunc(x, s, t);
		}
		integ_2n = h * ((myfunc(a, s, t) + myfunc(b, s, t)) / 2 + sum);
		sum = 0;
		k_iter++;
	} while (abs(integ_n - integ_2n) > r );
	return integ_2n;
}

void print_integral(double s, double t, double integral, double k_iter)
{
	cout << setw(6) << s << "|" << setw(10) << t << "|" << setw(10) << integral << "|" << setw(6) << k_iter << endl;
}