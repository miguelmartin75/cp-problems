#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    int n, k;
    cin >> n >> k;

    vector<int> skill(n);
    for(int i = 0; i < n; ++i) cin >> skill[i];

    vector<int> sorted = skill;
    sort(sorted.begin(), sorted.end());

    vector<int> mentors(n);
    for(int i = 0; i < n; ++i)
    {
        mentors[i] = lower_bound(sorted.begin(), sorted.end(), skill[i]) - begin(sorted);
    }

    for(int i = 0; i < k; ++i)
    {
        int u, v;
        cin >> u >> v;
        --u; --v;

        if(skill[u] > skill[v])
            mentors[u]--;
        else if(skill[v] > skill[u])
            mentors[v]--;
        mentors[u] = max(mentors[u], 0);
        mentors[v] = max(mentors[v], 0);
    }

    for(int i = 0; i < n; ++i)
    {
        cout << mentors[i] << ' ';
    }
    cout << endl;
}
