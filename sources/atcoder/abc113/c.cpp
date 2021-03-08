#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    vector<int> X(N);

    vector<vector<int>> P(N);
    for(int i = 0; i < M; ++i) {
        int p, y;
        cin >> p >> y;
        P[p].push_back(y);
    }

    vector<vector<int>> order(N);
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < P[i].size(); ++j) {
            order[i].push_back(j);
        }

        sort(order[i].begin(), order[i].end(), [&](int x, int y) {
            return P[i][x] < P[i][y];
        });
    }
    // x == order[p][i] + 1

    for(int i = 0; i < N; ++i) {
    }
}
