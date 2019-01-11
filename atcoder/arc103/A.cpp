#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;


    const int MAX_VAL = 1e5;
    vector<vector<int>> counts(2, vector<int>(MAX_VAL + 1, 0));
    vector<vector<int>> numbers(2);

    for(int i = 0; i < n; ++i) {
        int x; cin >> x;

        counts[i % 2][x]++;
        numbers[i % 2].push_back(x);
    }

    for(int i = 0; i < 2; ++i) {
        sort(numbers[i].begin(), numbers[i].end());
        numbers[i].erase(unique(numbers[i].begin(), numbers[i].end()), numbers[i].end());

        sort(numbers[i].begin(), numbers[i].end(), [&](int x1, int x2) { 
                return counts[i][x1] > counts[i][x2]; 
        });
    }

    int minCost = INT_MAX;
    for(int x : numbers[0]) {
        int curr = n/2 - counts[0][x];

        int i = 0;
        while(i < numbers[1].size() && numbers[1][i] == x) ++i;

        curr += n/2;

        if(i != numbers[1].size()) {
            curr -= counts[1][numbers[1][i]];
        }

        minCost = min(curr, minCost);
    }

    cout << minCost << '\n';
}
