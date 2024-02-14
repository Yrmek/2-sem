#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

double myfunc_a(double x, double s = 0)
{
	return ((x - 1) * (x - 1) - 5);
}

double myfunc_b(double x, double s = 0.7)
{
	return ((x - s) * (x - s) - exp(-x));
}

double find_root( double& x ,double(*myfunc)(double, double), int& d ,double s = 0.7, double a = -1.5 , double b = 2, double eps = 1e-6);

int main()
{
	short choice = 0;
	double eps = 1e-6;
	int k_iter = 0;
	double x = 0;
	double a = -1.5;
	double b = 2;
	double s = 0.7;
	enum  enmArrayInit
	{
		Option_a = 1, Option_b
	};

	cout << "Chose an option :" << endl
		<< "a) Write 1" << endl
		<< "b) Write 2" << endl
		<< "other options will stop the programm" << endl;
	cin >> choice;

	switch (choice)
	{
	case (Option_a):
		a = 2;
		b = 4;
		cout <<"x = "<< find_root(x, myfunc_a, k_iter, s, a, b, eps) << endl;
		cout << "f(x) = " << myfunc_a(x, s) << endl;
		cout << "k_iter = " << k_iter;
		break;
	case (Option_b):
		a = -1.5;
		b = 2;
		cout << setw(3) << "S" << "|" << setw(10) << "x" << "|" << setw(11) << "f(x)" << "|" << setw(6) << "k_iter" << endl;
		for (s = 0.7; s <= 1.6; s += 0.3)
			cout << setw(3) << s << "|" << setw(10) << x << "|" << setw(10) << myfunc_b(find_root( x ,myfunc_b, k_iter ,s, a, b, eps ), s) << "|" << setw(6) << k_iter << endl;
		break;
		;
	default: return 0;
	}
	return 0;
}

double find_root(double& x, double(*myfunc)(double, double), int& d, double s, double a, double b, double eps)
{
	d = 0;
	do
	{
		x = a - (b - a) / (myfunc(b, s) - myfunc(a, s)) * myfunc(a, s);
		if ((myfunc(x, s) > 0 && myfunc(a, s) < 0) || (myfunc(x, s) < 0 && myfunc(a, s) > 0))
		{
			b = x;
		}
		else
		{
			a = x;
		}
		d++;
	} while (abs(myfunc(x, s)) > eps);
	return x;
}