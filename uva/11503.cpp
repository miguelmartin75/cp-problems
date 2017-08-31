#include <bits/stdc++.h>
using namespace std;

class UFDS
{
public:

    UFDS() {}
    UFDS(int n) : rank(n, 0), parent(n, -1), size(n, 1) { }

    int Find(int x) 
    {
        if(parent[x] == -1) return x;
        return parent[x] = Find(parent[x]);
    }

    int Union(int x, int y) 
    {
        int r1 = Find(x);
        int r2 = Find(y);
        if(r1 == r2) return size[r1];
        if(rank[r1] < rank[r2]) 
        { 
            parent[r1] = r2; 
            size[r2] += size[r1];
            return size[r2];
        }
        else if(rank[r1] > rank[r2]) 
        { 
            parent[r2] = r1; 
            size[r1] += size[r2];
            return size[r1];
        }
        else 
        {
            parent[r1] = r2;
            rank[r2]++;
            size[r2] += size[r1];

            return size[r2];
        }
    }

    void AddNode()
    {
        rank.push_back(0);
        parent.push_back(-1);
        size.push_back(1);
    }

private:
    vector<int> rank;
    vector<int> parent;
    vector<int> size;
};

int main(int argc, char *argv[])
{
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i)
    {
        int f;
        cin >> f;

        int next_id = 0;
        map<string, int> ids;
        UFDS uf;
        for(int j = 0; j < f; ++j)
        {
            string s1, s2;
            cin >> s1 >> s2;
            if(ids.count(s1) == 0)
            {
                ids[s1] = next_id++;
                uf.AddNode();
            }

            if(ids.count(s2) == 0)
            {
                ids[s2] = next_id++;
                uf.AddNode();
            }

            cout << uf.Union(ids[s1], ids[s2]) << endl;
        }
    }
}
