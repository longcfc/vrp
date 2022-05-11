#include "solution.h"

class Perturbation
{
public:
    void bridgePerturbation(Solution *s, int maxBridges);
    void reinsertion(Solution *s);
    vector<pair<int, int> > makeBridges(const Solution *s, int bridge, int vehicle);

    friend ostream &operator<<(ostream &out, const Perturbation &c);
};
