#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    int n;
    cin >> n;

    int i = 1;
    int j = n*n;
    while(i < j)
    {
        cout << i << ' ' << j << '\n';
        i++;
        j--;
    }
}
