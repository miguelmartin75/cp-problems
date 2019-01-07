#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    const string YAKI = "YAKI";
    string str;
    cin >> str;
    bool val = true;
    for(int i = 0; i < 4; ++i)
    {
        if(str[i] != YAKI[i]) val = false;
    }

    cout << (val ? "Yes" : "No") << endl;
}
