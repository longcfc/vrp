#include "input.h"
#include "solution.h"
#include "construction.h"
#include "neighborhood.h"
#include "perturbation.h"
#include "localsearch.h"

#include<bits/stdc++.h>
using namespace std;

int main(int argc, char **argv)
{
	int seed = time(0);
	srand(seed);

	Input in(argc, argv);
	Solution sol(&in);
	LocalSearch ls(&in);

	int Imax = 50;
	int Iils = (in.numLocation() >= 150) ? in.numLocation() / 2 : in.numLocation();
	vector<double> R;
	R.push_back(0.00);
	for (int i = 1; i <= 25; i++)
		R.push_back(R[i - 1] + 0.01);

	sol = ls.GILSRVND(Imax, Iils, R);

	int cd = 300; // segundos

	cout<<sol<<endl;

	return 0;
}