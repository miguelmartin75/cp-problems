#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> pos;
    map<int, vector<int>> neg;

    int n;
    cin >> n;

    vector<int> remove;
    int amountNeg = 0;
    
    for(int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        if(x < 0) { neg[x].push_back(i); amountNeg++; }
        else if(x == 0) { if(remove.size() != n - 1) remove.push_back(i); } 
        else pos.push_back(i);
    }

    if(remove.size() == n - 1 && amountNeg == 1)
    {
        remove.pop_back();

        remove.push_back(neg.begin()->second.back());
        neg.begin()->second.pop_back();
        if(neg.begin()->second.empty()) neg.erase(neg.begin());
    }
    else if(amountNeg % 2 != 0)
    {
        remove.push_back(neg.begin()->second.back());
        neg.begin()->second.pop_back();
        if(neg.begin()->second.empty()) neg.erase(neg.begin());
    }


    for(int i : remove) {
        cout << "2 " << i + 1 << '\n';
    }

    for(int i = 1; i < pos.size(); ++i) {
        cout << "1 " << pos[i] + 1 << ' ' << pos[0] + 1 << '\n';
    }

    while(!neg.empty()) {
        cout << "1 " << neg.begin()->second.back() + 1 << ' ' << pos[0] + 1 << '\n';
        neg.begin()->second.pop_back();
        if(neg.begin()->second.empty()) neg.erase(neg.begin());
    }
}
