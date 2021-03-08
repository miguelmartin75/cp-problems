#include <bits/stdc++.h>
#include <ios>
using namespace std;

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> num2s{N, 0};
    vector<int> num4s{N, 0};
    vector<int> a{N, 0};

    int i = 0;
    for(int& x : a) {
        cin >> x;

        int y = x;
        int t = 0;
        while(y % 2 == 0 && y > 0) {
            t += 1;
            y /= 2;
        }

        if(t % 2 == 0) {
            num2s[i]++;
        } 

        if (t % 4 == 0) {
            num4s[i]++;
        }
        ++i;
    }
}
