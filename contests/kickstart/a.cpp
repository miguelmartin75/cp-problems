#include <bits/stdc++.h>
using namespace std;

int solve(string start)
{
    struct State
    {
        string clipboard;
        string str;
        string remainder;
        int n;
        State(string clipboard, string str, string remainder, int n) : clipboard{clipboard}, str{str}, remainder{remainder}, n{n} {}

        bool operator<(const State& s) const
        {
            return make_pair(str, clipboard) < make_pair(s.str, s.clipboard);
        }
    };

    queue<State> q;
    //map<State, bool> visited;
    q.emplace("", "", start, 0);

    while(!q.empty())
    {
        State s = q.front();
        q.pop();
        if(s.remainder.empty())
        {
            return s.n;
        }

        //visited[s] = true;

        {
            State adj{s.clipboard, s.str + s.remainder[0], s.remainder.substr(1), s.n + 1};
            q.emplace(adj);
            //if(!visited[adj])
        }

        if(!s.clipboard.empty() && s.clipboard.size() <= s.remainder.size())
        {
            State adj{s.clipboard, s.str + s.clipboard, s.remainder.substr(s.clipboard.size()), s.n + 1};
            q.emplace(adj);
            //if(!visited[adj])
        }

        {
            for(int i = 0; i < s.str.size(); ++i)
            {
                for(int j = 0; j < s.remainder.size(); ++j)
                {
                    //if(s.str[i + j] != s.remainder[j])
                    //{
                     //   break;
                   // }
                    string substr = string{s.str.begin() + i, s.str.begin() + i + j + 1};
                    if(substr != string{s.remainder.begin(), s.remainder.begin() + j + 1})
                    {
                        continue;
                    }

                    State adj{substr, s.str, s.remainder, s.n + 1};
                    q.emplace(adj);
                }
            }
        }
    }

    return -1;
}


int main(int argc, char *argv[])
{
    int t;
    cin >> t;

    for(int i = 0; i < t; ++i)
    {
        string s;
        cin >> s;
        cout << "Case #" << i + 1 << ": " << solve(s) << endl;
    }
}
