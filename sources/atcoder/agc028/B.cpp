#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    vector<int> values = {1, 2, 3, 4, 5, 6, 7};
    vector<int> perm = {0, 1, 2, 3, 4, 5, 6};

    map<int, int> counts;

    do {
        for(int i = 0; i < perm.size(); ++i) {
            counts[values[perm[i]]]++;
            int j = i - 1;
            while(j >= 0) {
                if(perm[j] >= perm[i]) break;
                counts[values[perm[j]]]++;
                --j;
            }

            j = i + 1;
            while(j < perm.size()) {
                if(perm[j] <= perm[i]) break;
                counts[values[perm[j]]]++;
                ++j;
            }


        }
    } while(next_permutation(perm.begin(), perm.end()));

    for(auto& x : counts) {
        cout << x.first << " = " << x.second << endl;
    }
}
