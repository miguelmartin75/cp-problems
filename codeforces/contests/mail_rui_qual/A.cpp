#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    int n;
    cin >> n;

    vector<int> parents(n - 1);
    for(int& x : parents) { cin >> x; --x; }
    parents.insert(parents.begin(), -1);

    stack<int> path;
    int el = n - 1;
    while(el != -1) {
        path.push(el);
        el = parents[el];
    }

    while(!path.empty()) {
        int x = path.top(); 
        path.pop();
        cout << x + 1 << ' ';
    }
    cout << endl;
}
