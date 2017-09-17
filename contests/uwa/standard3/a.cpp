#include <bits/stdc++.h>
using namespace std;

int naive(const vector<int>& A, int j, int k)
{
    int prev = j;
    int count = 0;
    for(int i = j; count < k && i < A.size(); ++i)
    {
        if(A[i] > A[prev])
        {
            prev = i;
            count += 1;
        }
    }
    return prev;
}

int lg2(int x)
{
    int c = 0;
    for(; x > 0; ++c) x /= 2;
    return c;
}

int succ(const vector<vector<int>>& arr, int x, int k)
{
    if(k == 0) return x;
    // if k is a power of 2
    if((k & (k-1)) == 0)
    {
        //cout << "allo" << endl;
        int l = lg2(k) - 1;
        return arr[l][x];
    }
    int temp = succ(arr, succ(arr, x, k/2), k - k/2);
    return temp;
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

        next[i] = j == -1 ? i : j;
    }

    vector<vector<int>> succ;
    succ.push_back(next);

    for(int k = 2; k < N; k *= 2)
    {
        succ.emplace_back();
        auto& prev = succ[succ.size() - 2];
        for(int i = 0; i < next.size(); ++i)
        {
            int p = prev[i];
            succ.back().push_back(prev[p]);
        }
    }

    for(int j = 0; j < Q; ++j)
    {
        int i, k;
        cin >> i >> k;

        cout << ::succ(succ, i, k) << '\n';
    }
    cout << flush;
}
