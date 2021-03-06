#include "pch.h"
#include "Curves.h"
#include "Circles.h"
#include "Ellipses.h"
#include "Helixes3D.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<shared_ptr<Curves>> fillingContainer(vector<shared_ptr<Curves>>, vector<shared_ptr<Curves>>);
int sumRadius(vector<shared_ptr<Curves>>);
bool iter(shared_ptr<Curves>, shared_ptr<Curves>);
void display(Curves*);

int main()
{

	int count, countCircles = 0, j = 0, N = 9, sum = 0;
	double t;
	vector<shared_ptr<Curves>> vec(N);

	//random curve selection
	for (int i = 0; i < N; i++)
	{
		count = rand() % 3 + 1;

		switch (count)
		{
		case 1:
			vec[i] = shared_ptr<Circles>(new Circles);
			countCircles++;
			cout << "Circles:" << endl;
			break;
		case 2:
			vec[i] = shared_ptr<Ellipses>(new Ellipses);
			cout << "Ellipses:" << endl;
			break;
		case 3:
			vec[i] = shared_ptr<Helixes3D>(new Helixes3D);
			cout << "Helixes3D:" << endl;
			break;
		default:
			break;
		}

		display(vec[i].get());
	}

	
	vector<shared_ptr<Curves>> cir(countCircles);
	cir = fillingContainer(vec, cir);

	//before sorting
	for (int i = 0; i < cir.size(); i++)		
	{
		cout << "no sorting: " << cir[i]->getRadius() << " ";
	}


	sort(cir.begin(), cir.end(), iter);

	//after sorting
	for (int i = 0; i < cir.size(); i++)
	{
		cout << endl << "after sorting" << cir[i]->getRadius() << " ";
	}

	sum = sumRadius(cir);

	cout << endl << "Sum = " << sum << endl;	
}

//filling the second container
vector<shared_ptr<Curves>> fillingContainer(vector<shared_ptr<Curves>> vec, vector<shared_ptr<Curves>> cir)
{
	int j = 0;

	for (int i = 0; i < vec.size(); i++)		
	{
		if (vec[i]->getType() == "Circles")
		{
			cir[j] = vec[i];
			j++;
		}
	}

	return cir;
}


bool iter(shared_ptr<Curves> a, shared_ptr<Curves> b)
{
	return (a->getRadius() < b->getRadius());
}

int sumRadius(vector<shared_ptr<Curves>> cir)
{
	int sum = 0;

	for (int i = 0; i < cir.size(); i++)
	{
		sum += cir[i]->getRadius();
	}

	return sum;
}


void display(Curves* vec)
{
	double t;

	if (vec->getType() == "Circles" || vec->getType() == "Ellipses")
	{
		t = rand() % 3 * 314;
		t = t / 100;
	}

	if (vec->getType() == "Helixes3D")
	{
		t = rand() % 5 * 314;
		t = t / 100;
	}

	cout << "Point and first derivative figure with t = " << t << endl;
	cout << vec->getPoint(t)[0] << "  " << vec->getPoint(t)[1] << "  " << vec->getPoint(t)[2] << "  " << endl;
	cout << vec->first_derivative(t)[0] << "  " << vec->first_derivative(t)[1] << "  " << vec->first_derivative(t)[2] << "  " << endl << endl;
}
