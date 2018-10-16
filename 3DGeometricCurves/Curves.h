#pragma once
#include <vector>

using namespace std;

struct Curves
{
public:
	virtual vector<double> getPoint(double t) = 0;		
	virtual vector<double> first_derivative(double t) = 0;		
	virtual string getType() = 0;
	virtual double getRadius() = 0;
};

