#include <iostream>
#include <vector>
using namespace std;

void search(vector<int>& ds, int n, int& minSol, int curr = 0, int depth = 0) {
    if(curr >= n && abs(n - curr) < abs(n - minSol)) {
        minSol = curr;
    }

    if(depth >= 5) return;

    vector<int> solution;
    for (int d : ds) {
        curr *= 10;
        curr += d;

        search(ds, n, minSol, curr, depth + 1);

        curr -= d;
        curr /= 10;
    }
}

int main(int argc, char *argv[]) {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> d(k);
    for(auto& x : d) cin >> x;

    vector<int> ds;
    for(int i = 0; i < 10; ++i) {
        bool add = true;
        for(auto& x : d) if(i == x) { add = false; break; }
        if(add) ds.push_back(i);
    }

    int minSol = 1000000;
    search(ds, n, minSol);
    cout << minSol << endl;
}
