#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    int a, b, c;
    cin >> a >> b >> c;

    int arr[] = {a, b, c};
    sort(arr, arr + 3);

    int res = max(0, arr[2] - (arr[0] + arr[1]) + 1);
    cout << res << '\n';
}
