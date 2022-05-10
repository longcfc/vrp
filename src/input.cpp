#include "input.h"

#include<bits/stdc++.h>
using namespace std;

int Input::numLocation() const {
    return this->numLocation_;
}

void Input::numLocationSet(unsigned d){
    this->numLocation_ = d;
}

int Input::numVehicle() const{
    return this->numVehicle_;
}

void Input::numVehicleSet(unsigned d){
    this->numVehicle_ = d;
}

double Input::capacity() const{
    return this->capacity_;
}

void Input::capacitySet(unsigned d){
    this->capacity_ = d;
}

double Input::demand(unsigned i) const{
    return this->demand_[i];
}

void Input::demandSet(unsigned i, double value){
    this->demand_[i] = value;
}

double Input::distance(unsigned i, unsigned j){
    return this->distance_[i][j];
}

void Input::distanceSet(unsigned i, unsigned j, double value){
    this->distance_[i][j] = value;
}

ostream &operator<<(ostream &out, Input &in)
{
    out << in.numLocation() << ' ' << in.numVehicle() << ' ' << in.capacity() << endl;
    for(int i=0;i<in.numLocation();i++) {
        for(int j=0;j<in.numLocation();j++) {
            out << in.distance(i,j) << "\t";
        }
        out << endl;
    }
    return out;
}

Input::Input(int argc, char **argv)
{

    if (argc < 2)
    {
        cout << "./cvrp [instance] " << endl;
        exit(1);
    }

    ifstream in(argv[1], ios::in);

    if (!in)
    {
        cerr << "File error: "<<argv[1]<<endl;
        exit(1);
    }

    in>>numLocation_>>numVehicle_>>capacity_;
    distance_ = vector<vector<double> >(numLocation(),vector<double>(numLocation(),numeric_limits<double>::infinity()));
    demand_ = vector<double>(numLocation());

    vector<double> x(numLocation());
    vector<double> y(numLocation());
    for(int i = 0; i < numLocation(); i++)
        in>>demand_[i]>>x[i]>>y[i];

    for(int i = 0; i < numLocation(); i++)
        for(int j = 0; j < numLocation(); j++)
            distance_[i][j] = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
}

    // int main(int argc, char* argv[]){
    //     Input in(argc,argv);
    //     cout<<in<<endl;
    //     return 0;
    // }