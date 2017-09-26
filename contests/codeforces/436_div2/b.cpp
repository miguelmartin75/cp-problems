#include <bits/stdc++.h>
using namespace std;

using Pos = pair<char, int>;

struct Compare
{
    bool operator()(const Pos& p1, const Pos& p2) const {
        return p1.first < p2.first;
    }
};

int main(int argc, char *argv[])
{
    int n;
    cin >> n;

    set<Pos, Compare> maxS;
    set<Pos, Compare> curr;

    for(int i = 0; i < n; ++i)
    {
        Pos ch;
        ch.second = i + 1;
        cin >> ch.first;
        if(isupper(ch.first))
        {
            if(curr.size() > maxS.size()) maxS = curr;
            curr.clear();
        }
        else
        {
            if(curr.count(ch) == 0)
            {
                curr.insert(ch);
            }
        }
    }

    if(curr.size() > maxS.size()) maxS = curr;
    curr.clear();

    cout << maxS.size() << endl;
}
