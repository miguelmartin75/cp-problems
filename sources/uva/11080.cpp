#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;

using Graph = vector<vector<int>>;

const int UNVISITED = -1;

int checkBipGraph(const Graph& graph, int i, int n, vector<int>& colours);
int count(const Graph& graph, int n)
{
    vector<int> colours;
    colours.resize(n, UNVISITED);

    int res = 0;
    for(int i = 0; i < n; ++i)
    {
        if(colours[i] == UNVISITED)
        {
            int temp = checkBipGraph(graph, i, n, colours);
            if(temp == -1) { return -1; }
            res += temp;
        }
    }
    return res;
}

int checkBipGraph(const Graph& graph, int i, int n, vector<int>& colours)
{
    queue<int> q;
    q.push(i);
    colours[i] = 0;

    int num_white = 0;
    int total = 0;
    bool res = true;
    while(!q.empty() && res)
    {
        int x = q.front();
        q.pop();

        const int colour = colours[x];

        total += 1;
        num_white += colour == 0;

        for(int v : graph[x])
        {
            if(colours[v] == colour)
            {
                res = false;
                break;
            }
            else if(colours[v] == UNVISITED)
            {
                colours[v] = 1 - colour;
                q.push(v);
            }
        }
    }

    if(!res)
    {
        return -1;
    }

    return max(1, min(num_white, total - num_white));
}

int main(int argc, char *argv[])
{
    int t;
    cin >> t;

    for(int i = 0; i < t; ++i)
    {
        int n;
        cin >> n;

        Graph graph;
        graph.resize(n);

        int e;
        cin >> e;
        for(int j = 0; j < e; ++j)
        {
            int x1, x2;
            cin >> x1 >> x2;
            graph[x1].push_back(x2);
            graph[x2].push_back(x1);
        }

        cout << (e == 0 ? n : count(graph, n)) << endl;
    }
}
