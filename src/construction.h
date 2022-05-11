#include "solution.h"

using namespace std;

class Construction
{
    public: 
        void calculateCostInsert(Solution* s, int vehicle);
        void constructiveProcedure(Solution* s, const double alpha);

    struct InsertionInfo {
        int inInsert;
        int edgeRemove;
        double cost;

    };

    static bool compareByCost(const InsertionInfo &a, const InsertionInfo &b)
    {
        return a.cost < b.cost;
    }

    //private:
    vector<int> CL;
    vector<InsertionInfo> costInsert;

    friend ostream & operator << (ostream &out, const Construction &c);
};