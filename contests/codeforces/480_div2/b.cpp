#include <bits/stdc++.h>
using namespace std;

int sps(vector<vector<char>>& graph, int sI, int sJ, int eI, int eJ, int dI, int dJ)
{
    const int rows = graph.size();
    const int cols = graph[0].size();
    vector<vector<int>> res(rows, vector<int>(cols, 0));

    for(int i = 0; i < rows; ++i)
    {
        res[i][cols - 1] = 1;
        res[i][0] = 1;
    }

    for(int j = 0; j < cols; ++j)
    {
        res[0][j] = 1;
        res[rows - 1][j] = 1;
    }
    
    for(int i = eI + dI; i >= 0 && i < rows; i += dI)
    {
        for(int j = eJ; j >= 0 && j < cols; j += dJ)
        {
            cout << "i = " << i << ", j = " << j << endl;
            if(graph[i][j] == '#') continue;

            int c1 = i - dI < 0 || i - dI >= rows ? 0 : res[i - dI][j];
            int c2 = j - dJ < 0 || j - dJ >= cols ? 0 : res[i][j - dJ];

            res[i][j] = c1 + c2;
        }
    }


        for(auto& row : res)
        {
            for(auto x : row)
            {
                cout << x << " ";
            }
            cout << endl;
        }
        cout << endl;
        cout << endl;

    return res[sI][sJ];
}

bool solve(vector<vector<char>>& graph, int k)
{

    const int rows = graph.size();
    const int cols = graph[0].size();

    sps(graph, 0, 0, 3, rows - 1, -1, -1);
    cout << endl;
    sps(graph, 3, 0, 0, rows - 1, 1, -1);
    return false;

    if(k % 2 == 0)
    {
        int num = k / 2;
        for(int i = 0; i < num; ++i)
        {
            graph[1][i + 1] = '#';
            graph[2][i + 1] = '#';
        }
        return true;
    }
    else if(cols > 3 && k == cols - 2)
    {
        int num = k;
        for(int i = 0; i < num; ++i)
        {
            graph[1][i + 1] = '#';
        }
        return true;
    }
    else return false;
}

int main(int argc, char *argv[])
{
    int n, k;
    cin >> n >> k;

    vector<vector<char>> graph(4, vector<char>(n, '.'));

    if(solve(graph, k))
    {
        cout << "YES" << endl;

        for(auto& row : graph)
        {
            for(auto x : row)
            {
                cout << x;
            }
            cout << endl;
        }
    }
    else
    {
        cout << "NO" << endl;
    }
}
