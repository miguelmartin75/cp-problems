#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    int n;
    cin >> n;

    map<long long, long long> counts;
    long long sum = 0;
    long long z = 0;
    for(int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;

        int balance = 0;
        int revBal = 0;
        bool flag = true;
        bool negFlag = true;
        for(int i = 0; i < s.size(); ++i)
        {
            char ch = s[i];
            char revCh = s[s.size() - 1 - i];
            balance += (ch == ')') ? -1 : 1;
            revBal += (revCh == ')') ? 1 : -1;

            if(balance < 0) flag = false;
            if(revBal < 0) negFlag = false;
        }

        if(balance == 0)
        {
            z += flag;
        }
        else
        {
            if((balance < 0 && negFlag) || (balance > 0 && flag))
                counts[balance]++;
        }
    }

    for(auto bal : counts)
    {
        if(bal.first > 0)
            sum += bal.second * counts[-bal.first];
    }

    cout << sum + z * z << endl;
}
