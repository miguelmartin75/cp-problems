#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    int n;
    cin >> n;

    int x;
    cin >> x;

    int max = x;
    int min = x;

    int amazing = 0;
    for(int i = 1; i < n; ++i)
    {
        cin >> x;
        if(x > max) { amazing++; max = x; }
        else if(x < min) { amazing++; min = x; }
    }
    
    cout << amazing << endl;
}
