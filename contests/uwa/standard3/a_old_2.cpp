#include <bits/stdc++.h>
using namespace std;

deque<int> dfs(const vector<int>& next, int i, unordered_map<int, deque<int>>& cache)
{
    deque<int> result;
    if(next[i] != -1)
    {
        auto it = cache.find(next[i]);
        if(it != cache.end())
        {
            result = it->second;
        }
        else
        {
            result = dfs(next, next[i], cache);
        }
    }

    result.push_front(i);
    cache[i] = result;
    return result;
}

unordered_map<int, deque<int>> dfs(const vector<int>& next)
{
    unordered_map<int, deque<int>> result;
    for(int i = 0; i < next.size(); ++i)
    {
        if(result.count(i)) continue;
        dfs(next, i, result);
    }
    return result;
}

int main(int argc, char *argv[])
{
    cin.tie(0);
    cin.sync_with_stdio(false);

    int N, Q;
    cin >> N >> Q;

    vector<int> A(N);
    vector<int> next(N, -1);
    

    auto seq = dfs(next);

    for(int j = 0; j < Q; ++j)
    {
        int i, k;
        cin >> i >> k;

        auto& s = seq[i];
        k = min((int)s.size() - 1, k);
        cout << seq[i][k] << '\n';
    }
    cout << flush;
}
