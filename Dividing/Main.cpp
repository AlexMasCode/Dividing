#include <iostream>
#include "Main.h"

using namespace std;

double Nth_root(double number, int pr);
double power(double x, int n);

int main()
{
	double number = 1.2;
	string powerNum = "2.1";

	int denominator = 1;

	bool dotWas = false;

	string numeratorStr = "";
	int numeratorInt = 0;

	for (char c : powerNum)
	{
		if (numeratorStr.empty() && c == '0')
		{
			continue;
		}

		if (c == '.' && dotWas == false)
		{
			dotWas = true;
			continue;
		}
		else if(c != '-')
		{
			numeratorStr = numeratorStr + c;
			if (dotWas == true)
			{
				denominator = denominator * 10;
			}
		}
	}

	numeratorInt = atoi(numeratorStr.c_str());


	int divid;

	int numeratorNSD = numeratorInt;
	int denominatorNSD = denominator;

	while (true)
	{
		if (numeratorNSD == denominatorNSD)
		{
			divid = numeratorNSD;
			break;
		}
		else if (numeratorNSD > denominatorNSD)
		{
			numeratorNSD = numeratorNSD - denominatorNSD;
		}
		else if (numeratorNSD < denominatorNSD)
		{
			denominatorNSD = denominatorNSD - numeratorNSD;
		}
	}

	numeratorInt = numeratorInt / divid;
	denominator = denominator / divid;

	cout << "Numerator: " << numeratorInt << endl;
	cout << "Denominator: " << denominator << endl;
	cout << "Common denominator: " << divid << endl;

	if (numeratorInt == 1)
	{
		if (atoi(powerNum.c_str()) < 0)
		{
			cout << "The number's result: " << number << "^(" << powerNum << ") = " << 1 / Nth_root(number, denominator) << endl;
		}
		else
		{
			cout << "The number's result: " << number << "^(" << powerNum << ") = " << Nth_root(number, denominator) << endl;
		}
		
	}
	else
	{

		if (atoi(powerNum.c_str()) < 0)
		{
			cout << "The number's result: " << number << "^(" << powerNum << ") = " << 1 / Nth_root(power(number, numeratorInt), denominator) << endl;
		}
		else
		{
			cout << "The number's result: " << number << "^(" << powerNum << ") = " << Nth_root(power(number, numeratorInt), denominator) << endl;
		}
		
	}

	return 0;
}

double power(double x, int n)
{
	double res = 1;

	for (int i = 1; i <= abs(n); i++)
	{
		res = res * x;
	}

	if (n < 0)
	{
		return 1 / res;
	}

	return res;
}

double Nth_root(double number, int pr)
{
	double eps = 0.000001;
	double prev_y, next_y;

	next_y = number;
	do
	{
		prev_y = next_y;
		next_y = (prev_y * (pr - 1) + number / power(prev_y, pr - 1)) / pr;
	} while (fabs(next_y - prev_y) > eps);
	return next_y;
}
