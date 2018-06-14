#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

struct UFDS
{
    UFDS(int n) : rank(n, 0), parent(n, -1) { }

    int Find(int x)
    {
        if(parent[x] == -1) return x;
        return parent[x] = Find(parent[x]);
    }

    void Union(int x, int y)
    {
        int r1 = Find(x);
        int r2 = Find(y);
        if(r1 == r2) return;
        if(rank[r1] < rank[r2]) { parent[r1] = r2; }
        else if(rank[r1] > rank[r2]) { parent[r2] = r1; }
        else
        {
            parent[r1] = r2;
            rank[r2]++;
        }
    }


private:
    vector<int> rank;
    vector<int> parent;
};


using Edge = tuple<int, int, int>;

int mst(int n, vector<Edge>& edgeList)
{
    sort(edgeList.begin(), edgeList.end(), [](auto& x1, auto& x2) { return get<2>(x1) < get<2>(x2); } );

    UFDS uf(n);
    int sum = 0;
    for(auto& e : edgeList)
    {
        int u = get<0>(e);
        int v = get<1>(e);
        if(uf.Find(u) == uf.Find(v)) continue;
        sum += get<2>(e);
        uf.Union(u, v);
    }
    return sum;
}

int main(int argc, char *argv[])
{
    vector<Edge> edges;

    string line;

    int sum = 0;
    int u = 0;
    while(getline(cin, line))
    {
        istringstream iss{line};
        int v = 0;
        string entry;
        while(getline(iss, entry, ','))
        {
            if(entry[0] != '-')
            {
                int size = atoi(entry.c_str());
                sum += size;
                edges.emplace_back(u, v, size);
            }
            ++v;
        }

        ++u;
    }

    auto save = mst(u, edges);
    cout << sum/2 - save << endl;
}
