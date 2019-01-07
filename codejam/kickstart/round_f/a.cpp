#include <bits/stdc++.h>
using namespace std;

bool bad(const vector<int>& vec)
{
    int min = 1;
    int max = vec.size();

    int right = (vec.size() - 1) / 2;
    int left = (vec.size() - 1) / 2;
    for(int i = 0; i < vec.size() - 1; ++i)
    {
        int el;
        if((vec.size() - i) % 2 == 0)
        {
            left -= i != 0;
            el = vec[left];
        }
        else
        {
            right += i != 0;
            el = vec[right];
        }

        if(el == min) min++;
        else if(el == max) max--;
        else return false;
    }
    return true;
}

int main(int argc, char *argv[])
{
    int t;
    cin >> t;

    for(int i = 0; i < t; ++i)
    {
        int n;
        cin >> n;

        vector<int> vec(n);
        for(int i = 0; i < n; ++i)
        {
            cin >> vec[i];
        }

        cout << "Case #" << i + 1 << ": ";
        cout << (bad(vec) ? "YES" : "NO") << '\n';
    }
    cout << endl;
}
