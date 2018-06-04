#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    int n;
    cin >> n;

    vector<int> neg;
    vector<int> pos;
    vector<int> zero;

    for(int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        if(x == 0) zero.push_back(x);
        else if(x > 0) pos.push_back(x);
        else neg.push_back(x);
    }

    if(pos.size() == 0)
    {
        for(int i = 0; i < 2; ++i)
        {
            pos.push_back(neg.back());
            neg.pop_back();
        }
    }

    if(neg.size() % 2 == 0)
    {
        zero.push_back(neg.back());
        neg.pop_back();
    }

    for(auto& s : {neg, pos, zero})
    {
        cout << s.size() << ' ';
        for(int x : s)
        {
            cout << x << ' ';
        }
        cout << endl;
    }
}
