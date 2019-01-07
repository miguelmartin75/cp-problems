#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    int n, x;
    cin >> n >> x;

    vector<int> A(n);
    for(int& y : A) cin >> y;

    sort(A.begin(), A.end());

    int delta = 0;

    auto lb = lower_bound(A.begin(), A.end(), x);
    auto ub = upper_bound(A.begin(), A.end(), x);

    int from = distance(A.begin(), lb);
    int to = distance(A.begin(), ub) - 1;

    if(*lb != x)
    {
        delta = 1;
        if(ub == A.end())
        {
            to = from;
        }
        else if(lb == A.begin())
        {
            to++;
            from = to;
        }
        else
        {
            to = from;
        }
    }

    while(!(to + 1 >= (n + delta + 1) / 2 && from + 1 <= (n + delta + 1) / 2))
    {
        if((from + 1) < (n + delta + 1) / 2)
        {
            to++;
        }
        delta++;
    }

    cout << delta << endl;
}
