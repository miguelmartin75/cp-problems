#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    int n;
    while(cin >> n)
    {
        bool awake[26] = {};
        bool mat[26][26] = {};

        int m;
        cin >> m;

        string woken;
        cin >> woken;

        //cout << "n = " << n << endl;
        //cout << "m = " << m << endl;
        //cout << "woken = " << woken << endl;

        for(char ch : woken)
        {
            awake[ch - 'A'] = true;
            mat[ch - 'A'][ch - 'A'] = true;
        }

        for(int i = 0; i < m; ++i)
        {
            string conn;
            cin >> conn;

            int x1 = conn[0] - 'A';
            int x2 = conn[1] - 'A';

            mat[x1][x1] = true;
            mat[x2][x2] = true;

            mat[x1][x2] = true;
            mat[x2][x1] = true;
        }

        int num_assigned = 0;
        for(int i = 0; i < 26; ++i)
        {
            num_assigned += mat[i][i];
        }

        for(int i = 0; num_assigned < n && i < 26; ++i)
        {
            if(!mat[i][i])
            {
                mat[i][i] = true;
                num_assigned++;
            }
        }
        
        vector<int> marked;
        marked.reserve(n);
        int year = 0;
        bool woke = true;

        for(;; ++year)
        {
            marked.clear();
            bool all_awake = true;
            for(int i = 0; i < 26; ++i)
            {
                if(awake[i] || !mat[i][i])
                {
                    continue;
                }

                all_awake = false;

                int num_awake = 0;
                for(int j = 0; j < 26; ++j)
                {
                    if(mat[i][j])
                        num_awake += awake[j];
                }

                if(num_awake >= 3)
                {
                    marked.push_back(i);
                }
            }

            if(all_awake) 
            { 
                break; 
            }

            if(marked.empty())
            {
                woke = false;
                break;
            }

            for(int x : marked)
            {
                awake[x] = true;
            }
        }

        if(woke)
        {
            cout << "WAKE UP IN, " << year << ", YEARS" << endl;
        }
        else
        {
            cout << "THIS BRAIN NEVER WAKES UP\n";
        }
    }
}
