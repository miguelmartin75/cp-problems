#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    int n;
    cin >> n;

    map<long long, long long> sums;
    long long count = 0;
    long long sum = 0;
    for(int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;

        sum += x;

        if(sum == 0) count++;

        count += sums[sum];
        sums[sum]++;
    }

    cout << count << endl;
}
