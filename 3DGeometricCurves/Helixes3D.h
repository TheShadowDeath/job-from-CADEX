#pragma once
#include <vector>
#include "Curves.h"

using namespace std;
struct Helixes3D : Curves
{
public:
	Helixes3D() 
	{
		a = rand() % 10 + 1;
		b = rand() % 10 + 1;
	}

	vector<double> getPoint(double t)
	{
		x = a * cos(t);
		y = a * sin(t);
		z = b * t;

		vector<double> vec{ x, y, z };

		return vec;
	}

	vector<double> first_derivative(double t)
	{
		x = a * (-sin(t));
		y = a * cos(t);
		z = b;

		vector<double> vec{ x, y, z };

		return vec;
	}

	string getType()
	{
		return "Helixes3D";
	}

	double getRadius()
	{
		return a;
	}

private:
	double x, y, z, a, b;
};

