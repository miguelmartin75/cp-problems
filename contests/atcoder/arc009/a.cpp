#include <iostream>
#include <vector>
using namespace std;
 
int main(int argc, char *argv[])
{
    int n;
    cin >> n;

    vector<long long> a(n), b(n);
    for(int i = 0; i < n; ++i) 
    {
        cin >> a[i] >> b[i];
    }
 
    long long num = 0;
    for(int i = n - 1; i >= 0; --i)
    {
        a[i] += num;
        num += (b[i] - a[i] % b[i]) % b[i];
    }
    
    cout << num << endl;
}
