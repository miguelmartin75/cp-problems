#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    int n;
    cin >> n;
    string str;
    cin >> str;

    int add = 1;
    int count = 0;
    for(int i = 2; i < n; ++i)
    {
        char& p1 = str[i - 2];
        char& p2 = str[i - 1];
        char& p3 = str[i];

        cout << p2 << ", " << p1 << endl;
        if(p2 == '1' && p1 == '1') 
        {
            ++add;
            cout << "add now is = " << add << endl;
            continue;
        }

        if(p3 == '0') continue;

        if(p1 == '1' && p2 == '0' && p3 == '1')
        {
            cout << "i = " << i << endl;
            if(i + 1 < n && i + 2 < n)
            {
                cout <<" Ay " << endl;
                if(add == 1 && str[i + 1] == '0' && str[i + 2] == '1')
                {
                    cout << "YO" << endl;
                    cout << "add = " << add << endl;
                    p1 = '1';
                    p2 = '0';
                    p3 = '0';
                    str[i + 1] = '1';
                    str[i + 2] = '0';
                    count += 1;
                    continue;
                }
            }
            cout << "add2 = " << add << endl;
            p1 = p3 = '0';
            p2 = '1';
            count += (add == 1 ? 1 : add - 1);
            i -= 2;
            add = 1;
        }
    }

    cout << str << endl;
    cout << count << endl;
}
