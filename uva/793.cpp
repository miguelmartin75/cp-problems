#include <bits/stdc++.h>
using namespace std;

class UFDS
{
public:

    UFDS(int n) : rank(n, 0), parent(n)
    {
        iota(parent.begin(), parent.end(), 0);
    }
    int Find(int x) 
    {
        if(parent[x] == x) return x;
        return parent[x] = Find(parent[x]);
    }

    void Union(int x, int y) 
    {
        int r1 = Find(x);
        int r2 = Find(y);
        if(rank[r1] < rank[r2])
        {
            parent[r1] = parent[r2];
        }
        else if(rank[r1] > rank[r2])
        {
            parent[r2] = parent[r1];
        }
        else
        {
            parent[r1] = parent[r2];
            rank[r2]++;
        }
    }

private:
    vector<int> rank;
    vector<int> parent;
};

int main(int argc, char *argv[])
{
    int t;
    cin >> t;

    for(int i = 0; i < t; ++i)
    {
        string str;
        int n;
        cin >> n;

        UFDS uf(n);
        cin.ignore();
        int correct = 0;
        int incorrect = 0;
        while(getline(cin, str))
        {
            if(str.empty()) break;
            istringstream iss{str};
            char ch;
            int c1, c2;
            iss >> ch >> c1 >> c2;

            c1 -= 1;
            c2 -= 1;

            if(ch == 'q')
            {
                bool b = uf.Find(c1) == uf.Find(c2);
                correct += b;
                incorrect += !b;
            }
            else
            {
                uf.Union(c1, c2);
            }
        }

        cout << correct << "," << incorrect << endl;
        if(i + 1 != t)
        {
            cout << endl;
        }
    }
}
