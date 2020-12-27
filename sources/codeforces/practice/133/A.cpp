#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    char ch;
    while(cin >> ch)
    {
        if(ch == 'H' || ch == 'Q' || ch == '9')
        {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
}
