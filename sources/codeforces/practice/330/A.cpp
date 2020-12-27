#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    int r, c;
    cin >> r >> c;

    vector<bool> row(r);
    vector<bool> col(c);

    char ch;
    for(int i = 0; i < r; ++i)
    {
        for(int j = 0; j < c; ++j)
        {
            cin >> ch;
            if(ch == 'S') row[i] = col[j] = true;
        }
    }

    int x = accumulate(col.begin(), col.end(), 0);
    int y = accumulate(row.begin(), row.end(), 0);

    int C = c - x;
    int R = r - y;

    cout << C*r + R*c - C*R << endl;
}
