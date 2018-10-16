#pragma once
#include <vector>
#include "Curves.h"

using namespace std;
struct Ellipses : Curves
{
public:
	Ellipses()
	{
		a = rand() % 10 + 1;
		b = rand() % 10 + 1;
	}

	vector<double> getPoint(double t)
	{
		x = a * cos(t);
		y = b * sin(t);

		vector<double> vec{ x, y, z };

		return vec;
	}

	vector<double> first_derivative(double t)
	{

		x = a * (-sin(t));
		y = b * cos(t);

		vector<double> vec{ x, y, z };

		return vec;
	}

	string getType()
	{
		return "Ellipses";
	}

	double getRadius()
	{
		return a;
	}

private:
	double  y, x, a, b, z = 0;
};

