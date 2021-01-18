#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
    cin.tie(0);
    cin.sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> a(n);
    for(auto& x : a) cin >> x;

    int min_cost = INT_MAX;
    for(int i = -100; i <= 100; ++i) {
        int cost = 0;
        for(auto& x : a) {
            cost += (x - i) * (x - i);
        }
        min_cost = min(cost, min_cost);
    }

    cout << min_cost << endl;
}
