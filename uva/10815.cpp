#include <iostream>
#include <set>
#include <algorithm>
#include <string>
#include <sstream>
#include <map>
using namespace std;

int main(int argc, char *argv[])
{
    string text;
    string line;
    while(getline(cin, line))
    {
        text += line + '\n';
    }

    istringstream iss{text};

    set<string> dict;
    string word;
    while(iss >> word)
    {
        transform(word.begin(), word.end(), word.begin(), [](char ch) {
            if(isalpha(ch)) return ch;
            else return ' ';
        });

        istringstream real_iss{word};
        string real_word;
        while(real_iss >> real_word)
        {
            transform(real_word.begin(), real_word.end(), real_word.begin(), ::tolower);
            dict.insert(real_word);
        }
    }

    for(const string& word : dict)
    {
        cout << word << '\n';
    }
}
