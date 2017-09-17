#include <bits/stdc++.h>
using namespace std;

vector<int> dfs(const vector<int>& next, int i, vector<vector<int>>& cache, vector<bool>& visited)
{
    vector<int> result;
    if(next[i] != -1)
    {
        if(visited[next[i]])
        {
            result = cache[next[i]];
        }
        else
        {
            result = dfs(next, next[i], cache, visited);
        }
    }

    result.push_back(i);
    visited[i] = true;
    cache[i] = result;
    return result;
}

vector<vector<int>> dfs(const vector<int>& next)
{
    vector<vector<int>> result(next.size());
    vector<bool> visited(next.size(), false);
    for(int i = 0; i < next.size(); ++i)
    {
        if(visited[i]) continue;
        dfs(next, i, result, visited);
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
    
    const int BUCKET_SIZE = (int)sqrt(N);
    vector<int> buckets;
    int curr_bucket = -1;
    for(int i = 0; i < N; ++i)
    {
        cin >> A[i];
        curr_bucket = max(curr_bucket, A[i]);
        if((i + 1) % BUCKET_SIZE == 0)
        {
            buckets.push_back(curr_bucket);
            curr_bucket = -1;
        }
    }

    if(N % BUCKET_SIZE != 0) buckets.push_back(curr_bucket);

    auto check_bucket = [&](int val, int b, int b_i)
    {
        for(int j = b_i; j <= BUCKET_SIZE; ++j)
        {
            int real_i = b * BUCKET_SIZE + j;
            int real_val = real_i >= (int)A.size() ? 0 : A[real_i];
            if(real_val > val)
            {
                return real_i;
            }
        }
        return -1;
    };

    for(int i = 0; i < N; ++i)
    {
        int b = i / BUCKET_SIZE;
        int b_i = i % BUCKET_SIZE;
        int j = check_bucket(A[i], b, b_i + 1);
        if(j == -1)
        {
            for(int k = b + 1; k < buckets.size(); ++k)
            {
                if(buckets[k] > A[i])
                {
                    j = check_bucket(A[i], k, 0);
                    break;
                }
            }
        }

        next[i] = j;
    }

    auto seq = dfs(next);

    for(int j = 0; j < Q; ++j)
    {
        int i, k;
        cin >> i >> k;

        auto& s = seq[i];
        k = min((int)s.size() - 1, k);
        k = s.size() - k - 1;
        cout << seq[i][k] << '\n';
    }
    cout << flush;
}
