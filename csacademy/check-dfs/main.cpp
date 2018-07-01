#include <bits/stdc++.h>
using namespace std;

bool possible(int i, vector<int>& p, int& j, vector<set<int>>& adj, vector<bool>& visited)
{
    visited[i] = true;
    while(j < p.size() && !adj[i].empty())
    {
        int next = p[j];
        if(adj[i].count(next) == 0) 
        {
            int num_visited = 0;
            for(int x : adj[i]) num_visited += visited[x];
            //cout << i + 1 << " does not have " << next + 1 << endl;
            //cout << "num visited = " << num_visited << endl;
            //cout << "size = " << adj[i].size() << endl;
            return num_visited == adj[i].size();
        }
        
        adj[i].erase(next);
        adj[next].erase(i);

        j++;

        if(!possible(next, p, j, adj, visited)) 
        {
            return false;
        }
    }
    return i == 0 ? j == p.size() : true;
}

int main(int argc, char *argv[])
{
    int n, m;
    cin >> n >> m;

    vector<int> p(n);
    for(int& x : p) { cin >> x; --x; }

    vector<set<int>> adj(n);
    for(int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        --u; --v;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    int j = 1;
    vector<bool> visited(n);
    cout << possible(0, p, j, adj, visited) << endl;
}
