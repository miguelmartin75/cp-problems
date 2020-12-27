#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    int n;
    while(cin >> n)
    {
        if(n == 0) break;

        priority_queue<int, vector<int>, greater<int>> q;
        for(int i = 0; i < n; ++i)
        {
            int x;
            cin >> x;
            q.push(x);
        }

        int cost = 0;
        while(q.size() > 1)
        {
            int x = q.top();
            q.pop();

            int y = q.top();
            q.pop();

            int inter = x + y;
            q.push(inter);

            cost += inter;
        }

        cout << cost << endl;
    }
}
