#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    vector<vector<int>> arr(3, vector<int>(3, 0));

    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 3; ++j)
        {
            cin >> arr[i][j];
        }
    }

    vector<vector<bool>> lights(3, vector<bool>(3, true));
    pair<int, int> adj[] = { {0, 0}, {-1, 0}, {1, 0}, {0, 1}, {0, -1} }; 
    for(int i = 0; i < 3; ++i)
        for(int j = 0; j < 3; ++j)
        {
            int amount = arr[i][j] % 2 == 0 ? 0 : 1;
            for(int k = 0; k < amount; ++k)
            {
                for(auto& a : adj)
                {
                    int I = a.first + i;
                    int J = a.second + j;
                    if(I < 0 || I >= 3) continue;
                    if(J < 0 || J >= 3) continue;

                    lights[I][J] = !lights[I][J];
                }
            }
        }

    for(auto& row : lights)
    {
        for(auto x : row)
        {
            cout << x;
        }
        cout << endl;
    }
}
