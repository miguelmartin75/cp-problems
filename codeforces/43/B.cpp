#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
    string s1, s2;

    getline(cin, s1);
    getline(cin, s2);

    int chars1[128] = {};
    int chars2[128] = {};

    for(char ch : s1) 
    {
        if(isspace(ch)) 
        {
            continue;
        }

        chars1[ch]++;
    }

    for(char ch : s2) 
    {
        if(isspace(ch)) 
        {
            continue;
        }

        chars2[ch]++;
    }

    bool result = true;
    for(int i = 0; i < 128; ++i)
    {
        if(chars2[i] > chars1[i])
        {
            result = false;
            break;
        }
    }

    cout << (result ? "YES" : "NO") << '\n';
}
