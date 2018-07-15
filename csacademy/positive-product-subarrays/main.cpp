#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    int n;
    cin >> n;

    int i = 0;
    int s = 0;
    while(n--)
    {
        int x;
        cin >> x;

        if(x == 0)
        {
            s += (i+1)*i/2;
            i = 0;
        }
        else
            i++;
    }

    s += (i+1)*i/2;
    cout << s << endl;
}
