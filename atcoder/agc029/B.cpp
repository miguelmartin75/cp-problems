#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    map<int, int> counts;
    map<int, set<int>> graph;

    int n;
    cin >> n;

    vector<int> arr(n);
    for(int& x : arr) { 
        cin >> x;

        for(int i = 0; i < 32; ++i) {
            int p = 1 << i;
            if(counts[p - x] > 0) {
                graph[x].insert(p - x);
                graph[p - x].insert(x);
            }
        }

        counts[x]++;
    }


    int pairs = 0;
    for(int x : arr) {
        if(graph[x].empty()) continue;

        int min_deg = INT_MAX;
        int choice = -1;
        for(int y : graph[x]) {
            if(counts[y] == 0) continue;

            if(graph[y].size() < min_deg) {
                choice = y;
                min_deg = graph[y].size();
            }
        }

        if(choice == -1) continue;

        counts[x]--;
        counts[choice]--;
        if(counts[x] == 0)
            graph[choice].erase(x);
        if(counts[choice] == 0)
            graph[x].erase(choice);

        pairs++;
    }

    cout << pairs << endl;
}
