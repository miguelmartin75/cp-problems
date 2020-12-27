#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    bool amp = false;
    bool f = true;

    string line;
    while(getline(cin, line))
    {
        int i = 0;
        while(i < line.size() && ::isspace(line[i])) ++i;

        if(line[i] == '#')
        {
            if(!amp && !f) cout << '\n';
            cout << line << '\n';
            amp = true;
        }
        else
        {
            while(i < line.size())
            {
                if(!isspace(line[i])) 
                {
                    cout << line[i];
                }
                ++i;
            }
            amp = false;
        }
        f = false;
    }
    if(!amp)
        cout << endl;
}
