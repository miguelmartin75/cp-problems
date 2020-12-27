#include <iostream>
#include <string>
#include <vector>
using namespace std;

const char HORIZ = 'h';
const char VERT = 'v';

int main()
{
    int n;
    cin >> n;

    string s1, s2;
    cin >> s1 >> s2;

    string blocks;
    for(int i = 0; i < s1.size(); ++i)
    {
        if(s1[i] == s2[i])
        {
            blocks += VERT;
        }
        else
        {
            blocks += HORIZ;
            i += 1;
        }
    }

    long long count = blocks[0] == VERT ? 3 : 6;
    for(int i = 1; i < blocks.size(); ++i)
    {
        int mul = 1;
        if(blocks[i - 1] == VERT) mul = 2;
        else if(blocks[i] == HORIZ) mul = 3;

        count *= mul;
        count %= 1000000007;
    }

    cout << count << endl;
}
