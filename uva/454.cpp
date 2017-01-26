#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main(int argc, char *argv[])
{
    int t;
    cin >> t;
    cin.ignore();

    string line;
    getline(cin, line);
    
    for (int i = 0; i < t; ++i)
    {
        vector<string> words;
        
        while(getline(cin, line))
        {
            if(line.empty())
            {
                break;
            }

            words.emplace_back(line);
        }

        sort(words.begin(), words.end());

        vector<map<char, int>> counts;
        for(auto& w : words)
        {
            map<char, int> count;
            for(auto ch : w)
            {
                if(isspace(ch)) continue;
                count[ch]++;
            }
            counts.emplace_back(count);
        }

        for(int i = 0; i < words.size(); ++i)
        {
            for(int j = i + 1; j < words.size(); ++j)
            {
                if(counts[i] == counts[j])
                {
                    cout << words[i] << " = " << words[j] << endl;
                }
            }
        }

        if(i != t - 1)
            cout << endl;
    }
}
