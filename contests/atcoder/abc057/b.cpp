#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main(int argc, char *argv[])
{
    vector<pair<int, int>> students;
    vector<pair<int, int>> checkpoints;
    int n, m;
    cin >> n >> m;

    students.reserve(n);
    checkpoints.reserve(m);

    for(int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        students.emplace_back(a, b);
    }

    for(int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        checkpoints.emplace_back(a, b);
    }

    for(auto& s : students)
    {
        pair<int, int> closest = checkpoints[0];
        int i = 0;
        int ind = 0;
        for(auto& c : checkpoints)
        {
            if(abs(s.first - c.first) + abs(s.second - c.second) < abs(closest.first - s.first) + abs(closest.second - s.second))
            {
                closest = c;
                ind = i;
            }
            i++;
        }
        cout << ind + 1 << endl;
    }
}
