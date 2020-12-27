#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(int argc, char *argv[])
{
    map<char, char> m;

    m['='] = '-';
    m['-'] = '0';
    m['0'] = '9';
    m['9'] = '8';
    m['8'] = '7';
    m['7'] = '6';
    m['6'] = '5';
    m['5'] = '4';
    m['4'] = '3';
    m['3'] = '2';
    m['2'] = '1';
    m['1'] = '`';

    m[']'] = '[';
    m['\\'] = ']';
    m['['] = 'P';
    m['P'] = 'O';
    m['O'] = 'I';
    m['I'] = 'U';
    m['U'] = 'Y';
    m['Y'] = 'T';
    m['T'] = 'R';
    m['R'] = 'E';
    m['E'] = 'W';
    m['W'] = 'Q';

    m['\''] = ';';
    m[';'] = 'L';
    m['L'] = 'K';
    m['K'] = 'J';
    m['J'] = 'H';
    m['H'] = 'G';
    m['G'] = 'F';
    m['F'] = 'D';
    m['D'] = 'S';
    m['S'] = 'A';

    m['/'] = '.';
    m['.'] = ',';
    m[','] = 'M';
    m['M'] = 'N';
    m['N'] = 'B';
    m['B'] = 'V';
    m['V'] = 'C';
    m['C'] = 'X';
    m['X'] = 'Z';

    string line;
    while(getline(cin, line))
    {
        for(auto& ch : line)
        {
            if(isspace(ch))
            {
                cout << ch;
                continue;
            }

            auto it = m.find(ch);
            if(it == m.end())
                continue;

            cout << it->second;
        }
        cout << endl;
    }
}
