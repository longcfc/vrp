#include "construction.h"
#include<bits/stdc++.h>

using namespace std;

void Construction::constructiveProcedure(Solution *s, const double alpha) 
{
    s->totalDistance_ = 0;
    for(int v=0;v < s->in->numVehicle();v++) {
        CL.clear();
        for(int i=1;i < s->tour_[v].size()-1;i++) {
            CL.push_back(s->tour_[v][i]);
        }

        s->tour_[v] = {0,0};
        s->tourDistance_[v] = 0;
        calculateCostInsert(s,v);
        while (CL.size() > 0) {
            int position = rand() % (int(floor(costInsert.size() * alpha)) + 1);
            s->tour_[v].insert(s->tour_[v].begin() + costInsert[position].edgeRemove + 1, costInsert[position].inInsert);
            s->tourDistance_[v] += costInsert[position].cost;
            remove(CL.begin(), CL.end(), costInsert[position].inInsert);
            CL.resize(CL.size() - 1);
            calculateCostInsert(s,v);
        }
        s->totalDistance_ += s->tourDistance_[v];
    }
}

void Construction::calculateCostInsert(Solution *s, int vehicle)
{

    costInsert.resize((s->tour_[vehicle].size() - 1) * CL.size());

    for (unsigned i = 0, j = 1, l = 0; i < s->tour_[vehicle].size() - 1; i++, j++)
    {
        for (auto k : CL)
        {
            costInsert[l].cost =
                s->in->distance(s->tour_[vehicle][i], k) +
                s->in->distance(s->tour_[vehicle][j], k) -
                s->in->distance(s->tour_[vehicle][i], s->tour_[vehicle][j]);
            costInsert[l].inInsert = k;
            costInsert[l].edgeRemove = i;
            l++;
        }
    }
    sort(costInsert.begin(), costInsert.end(), compareByCost);
}

ostream &operator<<(ostream &out, const Construction &c)
{

    out << "inInsert"
        << " | "
        << "edgeRemove"
        << " | "
        << "cost" << endl;

    for (size_t i = 0; i < c.costInsert.size(); i++)
    {
        out << setw(10) << c.costInsert[i].inInsert << " | " << setw(14) << c.costInsert[i].edgeRemove << " | " << setw(5) << c.costInsert[i].cost << endl;
    }
    return out;
}

// int main(int argc, char *argv[])
// {
//     Input in(argc, argv);
//     Solution s(&in);
//     Construction c;
//     c.constructiveProcedure(&s,0.1);
//     return 0;
// }
