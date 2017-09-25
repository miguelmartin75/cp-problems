#include <bits/stdc++.h>
using namespace std;

int h, w, d;

vector<pair<int, int>> neigh;

set<char> COLOUR = { 'R', 'G', 'Y', 'B' };

set<char> dfs(int i, int j, vector<string>& graph, const vector<pair<int, int>>& neigh)
{
    if(COLOUR.count(graph[i][j]))
    {
        return { graph[i][j] };
    }

    set<char> valid = COLOUR;
    for(auto& n : neigh)
    {
        int i2 = i + n.first;
        int j2 = j + n.first;
        if(!(i2 > 0 && i2 < w)) continue;
        if(!(j2 > 0 && j2 < h)) continue;

        if(graph[i2][j2] != ' ')
        {
            valid.remove();
        }
    }

    auto x = dfs(i2, j2, graph);
}

void dfs(vector<string>& graph, const vector<pair<int, int>>& neigh)
{
    for(int i = 0; i < graph.size(); ++i)
    {
        for(int j = 0; j < graph[i].size(); ++j)
        {
            if(graph[i][j] != ' ') continue;
            dfs(i, j, graph, neigh);
        }
    }
}

int main(int argc, char *argv[])
{
    cin >> h >> w >> d;

    for(int i = 0; i < d / 2; ++i)
    {
        int j = d - i;
        neigh.emplace_back(i, j);
        if(i != j)
            neigh.emplace_back(j, i);
    }

    vector<string> graph;
    for(int i = 0; i < h; ++i)
    {
        string temp;
        temp.resize(w);
        graph.push_back(temp);
    }

    dfs(graph, neigh);
}
