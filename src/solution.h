#include "input.h"
#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
        Solution(Input *in);

        double totalDistance();
        void totalDistanceSet(double value);

        double tourDistance(int vehicle) const;
        double tourDistanceSet(int vehicle, double value);

        double capacityVehicle(int vehicle) const;
        void capacityVehicleSet(int vehicle, double value);

        int tour(int vehicle, int location) const;
        int tourSet(int v, int location, double value);

        friend ostream &operator<<(ostream &out, Solution &c);

        double totalDistance_;
        vector<double> capacityVehicle_;
        vector<double> tourDistance_;
        vector<vector<int> > tour_;
        Input *in;
};