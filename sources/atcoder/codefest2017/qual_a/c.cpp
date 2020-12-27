#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    map<char, int> counts;

    int h, w;
    cin >> h >> w;
    for(int i = 0; i < h; ++i)
    {
        for(int j = 0; j < w; ++j)
        {
            char ch;
            cin >> ch;
            counts[ch]++;
        }
    }

    // 4s
    bool valid = true;
    //cout << (h/2) * (w/2) << endl;
    for(int i = 0; i < (h/2) * (w/2); ++i)
    {
        char ch = 0;
        for(auto& count : counts)
        {
            if(count.second >= 4)
            {
                ch = count.first;
                break;
            }
        }

        if(ch == 0) valid = false;
        counts[ch] -= 4;
    }

    int count = 0;
    if(w % 2 != 0 && h % 2 != 0)
    {
        count = h / 2 + w / 2;
    }
    else if(w % 2 != 0 || h % 2 != 0)
    {
        count = w % 2 != 0 ? h / 2 : w / 2;
    }

    for(int i = 0; i < count; ++i)
    {
        char ch = 0;
        for(auto& count : counts)
        {
            if(count.second >= 2)
            {
                ch = count.first;
                break;
            }
        }

        if(ch == 0) valid = false;
        counts[ch] -= 2;
    }

    char ch = 0;
    for(auto& count : counts)
    {
        if(count.second >= 1)
        {
            ch = count.first;
            break;
        }
    }

    if(w % 2 != 0 && h % 2 != 0)
    {
        valid &= ch != 0;
    }

    cout << (valid ? "Yes" : "No") << endl;
}
