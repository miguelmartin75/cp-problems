#include <iostream>
#include <vector>
using namespace std;

int arr[100][100] = {};

int max_1d(int* arr, int n)
{
    int ith = arr[0];
    int ans = ith;
    for(int i = 1; i < n; ++i)
    {
        ith = max(arr[i], ith + arr[i]);
        ans = max(ith, ans);
    }
    return ans;
}

int main(int argc, char *argv[])
{
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cin >> arr[i][j];
        }
    }

    int rolling_max = -128 * 100 * 100;
    for(int i = 0; i < n; ++i)
    {
        int comp[100] = {};
        for(int j = i; j < n; ++j)
        {
            for(int k = 0; k < n; ++k)
            {
                comp[k] += arr[j][k];
            }

            rolling_max = max(rolling_max, max_1d(comp, n));
        }
    }

    cout << rolling_max << endl;
}
