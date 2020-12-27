#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n;
pair<int, pair<ll, int>> O(int i, map<int, vector<tuple<int, ll, int>>>& o)
{
    auto& kids = o[i];
    if(kids.empty()) return {i, {0, -1}};
    auto m = O(get<0>(kids[0]), o);
    m.second.first += get<1>(kids[0]);
    m.second.second = get<2>(kids[0]);
    for(int j = 1; j < kids.size(); ++j)
    {
        auto& child = kids[j];
        auto k = O(get<0>(child), o);
        k.second.first += get<1>(child);
        k.second.second = get<2>(child);
        if(m.second < k.second)
        {
            m = k;
        }
    }
    return m;
}

pair<int, pair<ll, int>> farthest(int i, int d, vector<int>& w, map<int, vector<tuple<int, ll, int>>>& o)
{
    pair<int, pair<ll, int>> res = O((i + d) % n, o);

    for(int j = d - 1; j >= 0; --j)
    {
        const int indx = (i + j) % n;
        auto temp = make_pair(res.second.first + w[indx], res.second.second);
        auto m = O(indx, o);
        if(temp >= m.second)
        {
            res = {res.first, temp};
        }
        else
        {
            res = m;
        }
    }

    return res;
}

void cyclicalQueries(vector<int> w, int m) 
{
    int num_nodes = n;
    stack<int> freeIds;

    map<int, vector<tuple<int, ll, int>>> o;
    map<int, tuple<int, ll, int>> parent;
    auto remove = [&](int x) {
        int y = farthest(x, n - 1, w, o).first;
        auto& p = parent[y];
        o[get<0>(p)].pop_back();

        parent.erase(y);
        o.erase(y);

        freeIds.push(y);
        --num_nodes;
    };

    auto add = [&](int x, int w, int t) {
        int node;
        if(freeIds.empty()) node = num_nodes++;
        else { node = freeIds.top(); freeIds.pop(); }

        //cout << "node = " << node << endl;
        //cout << "x = " << x << endl;
        parent[node] = make_tuple(x, w, t);
        o[x].emplace_back(node, w, t);
    };

    for(int i = 0; i < m; ++i) {
        int q;
        cin >> q;

        if(q == 1) {
            int x, m;
            cin >> x >> m;

            add(farthest(x - 1, n - 1, w, o).first, m, i);
        }
        else if(q == 2) {
            int x, w;
            cin >> x >> w;

            add(x - 1, w, i);
        }
        else if(q == 3) {
            int x;
            cin >> x;

            remove(x - 1);
        }
        else {
            int x;
            cin >> x;

            auto ans = farthest(x - 1, n - 1, w, o).second;
            cout << ans.first << '\n';
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    vector<int> arr(n);
    for(int& x : arr) cin >> x;

    int m;
    cin >> m;
    cyclicalQueries(arr, m);
}
