#include <bits/stdc++.h>
using namespace std;

int n, m;
int sX, sY;
int x, y;

bool visited[2001][2001];
bool lab[2001][2001];

int bfs01() {
    queue<tuple<int, int, int, int>> q;
    q.emplace(sX, sY, 0, 0);

    while(!q.empty()) {
        int i, j, mX, mY;
        tie(i, j, mX, mY) = q.front();
        q.pop();

        if(visited[i][j]) continue;
        visited[i][j] = true;

        for(auto left : {false, true}) {
            int nI = i;
            int nJ = left ? j - 1 : j + 1;
            if(nJ < 0 || nJ >= m) continue;
            if(visited[nI][nJ] || lab[nI][nJ]) continue;

            int nX = mX + left;
            int nY = mY + !left;
            if(nX > x || nY > y) continue;

            q.emplace(nI, nJ, nX, nY);
        }

        for(auto up : {false, true}) {
            int nI = up ? i - 1 : i + 1;
            int nJ = j;
            if(nI < 0 || nI >= n) continue;
            if(visited[nI][nJ] || lab[nI][nJ]) continue;

            q.emplace(nI, nJ, mX, mY);
        }
    }

    int ans = 0;
    for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) ans += visited[i][j];
    return ans;
}

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    cin >> sX >> sY;
    cin >> x >> y;

    --sX; --sY;

    for(int i = 0; i < n; ++i) {
        string line;
        cin >> line;
        for(int j = 0; j < line.size(); ++j) {
            if(line[j] == '*') lab[i][j] = true;
        }
    }

    auto ans = bfs01();
    cout << ans << '\n';
}
