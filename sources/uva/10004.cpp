#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

using Graph = vector<vector<int>>;

bool isBipartite(const Graph& graph, int n)
{
    if(n == 0) return false;

    const int UNVISITED = -1;
    vector<int> colours(n, UNVISITED);

    queue<int> q;
    q.push(0);
    colours[0] = 0;

    bool res = true;
    while(!q.empty() && res)
    {
        int x = q.front();
        q.pop();

        const int colour = colours[x];

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

    return res;
}

int main(int argc, char *argv[])
{
    while(true)
    {
        int n;
        cin >> n;
        if(n == 0) break;

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

        if(isBipartite(graph, n))
        {
            cout << "BICOLORABLE." << endl;
        }
        else
        {
            cout << "NOT BICOLORABLE." << endl;
        }
    }
}
