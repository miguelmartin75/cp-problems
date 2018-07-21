#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    ifstream in{"input.txt"};
    ofstream out{"output.txt"};

    int n, m;
    in >> n >> m;

    char max = 'B';
    char min = 'G';
    if(n < m) 
    {
        swap(n, m);
        swap(max, min);
    }

    int i = 0;
    int j = 0;
    while(i < n || j < m)
    {
        if(i < n) { out << max; i++; }
        if(j < m) { out << min; j++; }
    }
    out << '\n';
}
