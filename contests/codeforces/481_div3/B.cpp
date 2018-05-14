#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    int n;
    cin >> n;

    int len = 0;
    int result = 0;
    for(int i = 0; i < n; ++i)
    {
        char ch;
        cin >> ch;

        if(ch == 'x') len++;
        else
        { 
            if(len >= 3)
                result += (len - 3) + 1;
            len = 0;
        }
    }

    if(len >= 3)
        result += (len - 3) + 1;

    cout << result << endl;
}
