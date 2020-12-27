#include <bits/stdc++.h>
using namespace std;

const int MAX_X = 10001;
const int MAX_Y = 10001;
int graph[MAX_X][MAX_Y] = {};

int main(int argc, char *argv[])
{
    int g;
    cin >> g;
    for(int i = 0; i < g; ++i)
    {
        int x, y; 
        cin >> x >> y;
        graph[x][y]++;
    }
    
    int amount = 0;

    int m;
    cin >> m;
    for(int i = 0; i < m; ++i)
    {
        int x, y, r;
        cin >> x >> y >> r;

        for(int x2 = x - r; x2 <= x + r; ++x2)
        {
            if(x2 < 0) continue;
            if(x2 >= MAX_X) break;
            for(int y2 = y - r; y2 <= y + r; ++y2)
            {
                if(y2 < 0) continue;
                if(y2 >= MAX_Y) break;
                if((x2 - x)*(x2 - x) + (y2 - y)*(y2 - y) > r * r) continue;

                amount += graph[x2][y2];
                graph[x2][y2] = 0;
            }
        }
    }

    cout << g - amount << endl;
}
