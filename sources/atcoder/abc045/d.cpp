#include <iostream>
#include <map>
#include <utility>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
    cin.tie(0);
    cin.sync_with_stdio(false);

    long long h, w, n;
    cin >> h >> w >> n;

    //vector<vector<bool>> grid(h, vector<bool>(w, false));
    map<pair<int, int>, bool> grid;

    long long counts[10] = {};
    counts[0] = (w - 2) * (h - 2);
    for (int c = 0; c < n; c++) {
        int A, B;
        cin >> A >> B;

        --A;
        --B;

        auto pos = make_pair(A, B);
        if(grid.count(pos) > 0) continue;

        int sA = A - 2, sB = B - 2;
        while(sA < 0) ++sA;
        while(sB < 0) ++sB;

        for(int a = sA; a <= A && a + 2 < h; ++a) {
            for(int b = sB; b <= B && b + 2 < w; ++b) {
                int num_black = 0;
                for(int i = a; i < a + 3; ++i) {
                    for(int j = b; j < b + 3; ++j) {
                        if(grid.count(make_pair(i, j)) > 0) {
                            num_black++;
                        }
                    }
                }

                counts[num_black + 1]++;
                counts[num_black]--;
            }
        }

        grid[pos] = true;
    }

    for(int i = 0; i < 10; ++i) {
        cout << counts[i] << endl;
    }
}
