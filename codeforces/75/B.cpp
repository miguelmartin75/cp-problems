#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>
using namespace std;

int main(int argc, char *argv[])
{
    string me;
    cin >> me;

    int n;
    cin >> n;
    cin.ignore();

    map<string, int> scores;

    string line;
    for(int i = 0; i < n; ++i)
    {
        getline(cin, line);

        string name1;
        string buffer;
        istringstream ss{line};

        // get the first guys name
        ss >> name1;

        ss >> buffer;

        // work out the score
        int score;
        switch(buffer[0])
        {
            case 'p':
                ss >> buffer;
                score = 15;
                break;
            case 'c':
                ss >> buffer;
                score = 10;
                break;
            case 'l':
            default:
                score = 5;
                break;
        }

        ss >> buffer;

        string name2 = buffer.substr(0, buffer.size() - 2);

        auto& x1 = scores[name1];
        auto& x2 = scores[name2];
        if(name1 == me)
        {
            scores[name2] += score;
        } 
        else if(name2 == me)
        {
            scores[name1] += score;
        }
    }

    vector<pair<int, string>> result;
    for(auto& x : scores) 
    {
        if(x.first == me)
        {
            continue;
        }

        result.emplace_back(-x.second, x.first);
    }

    sort(result.begin(), result.end());

    for(auto& x : result)
    {
        cout << x.second << endl;
    }
}
