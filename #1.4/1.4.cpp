#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

double myfunc_a(double x, double s)
{
	return ((x - 1) * (x - 1) - 5);
}

double myfunc_b(double x, double s)
{
	return ((x - s) * (x - s) - exp(-x));
}

double findroot(double s, double a, double b, double r, double& x, double(*myfunc_b)(double, double), int& d)
{
	d = 0;
	do
	{
		x = a - (b - a) / (myfunc_b(b, s) - myfunc_b(a, s)) * myfunc_b(a, s);
		if ((myfunc_b(x, s) > 0 && myfunc_b(a, s) < 0) || (myfunc_b(x, s) < 0 && myfunc_b(a, s) > 0))
		{
			b = x;
		}
		else
		{
			a = x;
		}
		d++;
	} while (abs(myfunc_b(x, s)) > r);
	return x;
}

int main()
{
	short choice = 0;
	double r = 1e-6;
	int k_iter = 0;
	double x = 0;
	double a = -1.5;
	double b = 2;
	double s = 0.7;

	cout << "Chose an option :" << endl
		<< "a) Write 1" << endl
		<< "b) Write 2" << endl
		<< "other options will stop the programm" << endl;
	cin >> choice;
	switch (choice)
	{
	case (1):
		a = 2;
		b = 4;
		cout << findroot(s, a, b, r, x, myfunc_a, k_iter) << endl;
		cout << k_iter;
		break;
	case (2):
		a = -1.5;
		b = 2;
		cout << setw(3) << "S" << "|" << setw(10) << "x" << "|" << setw(11) << "f(x)" << "|" << setw(6) << "k_iter" << endl;
		for (s = 0.7; s <= 1.6; s += 0.3)
			cout << setw(3) << s << "|" << setw(10) << x << "|" << setw(10) << myfunc_b(findroot(s, a, b, r, x, myfunc_b, k_iter), s) << "|" << setw(6) << k_iter << endl;
		break;
		;
	default: return 0;
	}
	return 0;
}