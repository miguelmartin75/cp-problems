#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    bool taken[30*30 + 1] = {};
    int temp[30] = {};
    for(int i = 0; i < k; ++i)
    {
        cin >> temp[i];
        taken[temp[i]] = true;
    }

    int ptr = 1;
    for(int i = 0; i < k; ++i)
    {
        cout << temp[i] << ' ';
        for(int j = 1; j < n; ++j)
        {
            while(taken[ptr]) ptr++;
            taken[ptr] = true;
            cout << ptr << ' ';
        }
        cout << '\n';
    }
}
