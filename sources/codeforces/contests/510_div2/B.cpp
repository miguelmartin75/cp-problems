#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    int n;
    cin >> n;

    int minCosts[8] = {};
    for(int i = 0; i < 8; ++i) {
        minCosts[i] = INT_MAX;
    }

    vector<pair<bitset<3>, int>> vals;
    for(int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;

        string vit;
        cin >> vit;

        bool hasA = false;
        bool hasB = false;
        bool hasC = false;
        for(char ch : vit) {
            if(ch == 'A') hasA = true;
            if(ch == 'B') hasB = true;
            if(ch == 'C') hasC = true;
        }

        bitset<3> index;
        index[0] = hasA;
        index[1] = hasB;
        index[2] = hasC;

        for(int i = 0; i < 3; ++i) {
            if(index[i]) {
                int attrib = 1 << i;
                minCosts[attrib] = min(minCosts[attrib], x);
            }
        }

        minCosts[index.to_ulong()] = min(minCosts[index.to_ulong()], x);
        vals.emplace_back(index, x);
    }

    int minCost = INT_MAX;
    for(auto& vit : vals) {
        auto needed = ~vit.first;
        int costForNeed = needed.none() ? 0 : minCosts[needed.to_ulong()];
        if(costForNeed == INT_MAX) continue;
        minCost = min(minCost, costForNeed + vit.second);
    }

    int seperate = 0;
    for(int i = 0; i < 3; ++i) {
        int costForAttrib = minCosts[1 << i];
        if(costForAttrib != INT_MAX) 
            seperate += costForAttrib;
        else {
            seperate = INT_MAX;
            break;
        }
    }

    minCost = min(seperate, minCost);

    if(minCost == INT_MAX) minCost = -1;
    cout << minCost << endl;
}
