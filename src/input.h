#include<bits/stdc++.h>

using namespace std;

class Input {
    public:
        Input(int, char **);

        int numLocation() const;
        void numLocationSet(unsigned d);

        int numVehicle() const;
        void numVehicleSet(unsigned d);

        double capacity() const;
        void capacitySet(unsigned d);

        double demand(unsigned i) const;
        void demandSet(unsigned i, double value);

        double distance(unsigned i, unsigned j);
        void distanceSet(unsigned i, unsigned j, double value);

        friend ostream &operator<<(ostream &out, Input &c);

    private:
        int numLocation_;
        int numVehicle_;
        int capacity_;
        vector<double> demand_;
        vector<vector<double>> distance_;
};