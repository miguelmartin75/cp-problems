#include <iostream>
#include <map>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int N, Q;
    cin >> N >> Q;

    vector<int> A(N);

    const int BUCKET_SIZE = (int)sqrt(N);
    vector<int> buckets;

    int new_max = -1;
    for(int i = 0; i < N; ++i)
    {
        cin >> A[i];
        new_max = max(A[i], new_max);
        if((i + 1) % BUCKET_SIZE == 0)
        {
            buckets.push_back(new_max);
            new_max = -1;
        }
    }

    vector<map<int, int>> table;
    table.emplace_back();

    auto check_bucket = [&A, &BUCKET_SIZE](int b, int b_i)
    {
        int i = b * A.size() + b_i;
        for(int j = i; (j % BUCKET_SIZE) != 0; ++j)
        {
            if(A[j] > A[i])
            {
                return j;
            }
        }
        return -1;
    };

    // do K=1
    for(int i = 0; i < N; ++i)
    {
        int b = i / BUCKET_SIZE;
        int b_i = i % BUCKET_SIZE;

        // check first bucket
        int j = check_bucket(b, b_i);


        if(j == -1)
        {
            cout << "aint found shit\n";
            int b = i / BUCKET_SIZE;
            for(int k = b + 1; k < buckets.size(); ++k)
            {
                if(A[i] < buckets[k])
                {
                    j = check_bucket(k, 0);
                    break;
                }
            }
        }

        table.back()[i] = j;
    }

    for(auto& x : table[0])
    {
        cout << x.first << " = " << x.second << '\n';
    }
    cout << endl;
}
