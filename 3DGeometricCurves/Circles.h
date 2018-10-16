#pragma once
#include <vector>
#include "Curves.h"

using namespace std;
struct Circles : Curves
{
public:
	Circles()
	{
		r = rand() % 10;
	}

	vector<double> getPoint(double t)
	{
		x = r * cos(t);
		y = r * sin(t);

		vector<double> vec{ x, y, z };

		return vec;
	}

	vector<double> first_derivative(double t)
	{
		x = r * (-sin(t));
		y = r * cos(t);

		vector<double> vec{ x, y, z };

		return vec;
	}

	double getRadius()
	{
		return r;
	}

	string getType()
	{
		return "Circles";
	}


private:
	double x, y, r, z = 0;
};

