#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
    const vector<string> keypad_layout = 
    {
        { "abc" },
        { "def" },
        { "ghi" },
        { "jkl" },
        { "mno" },
        { "pqrs" },
        { "tuv" },
        { "wxyz" },
        { " " }
    };
    
    map<char, int> key_costs;
    for(auto& button : keypad_layout)
    {
        for(int i = 0; i < button.length(); ++i)
        {
            key_costs[button[i]] = i + 1;
        }
    }

    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; ++i)
    {
        string line;
        getline(cin, line);

        int cost = 0;
        for(auto ch : line)
        {
            cost += key_costs[ch];
        }
        cout << "Case #" << i + 1 << ": " << cost << endl;
    }
}
