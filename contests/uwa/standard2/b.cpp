#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

struct El
{
    int val;
    int index;
    El(int index, int val) : val(val), index(index) {}
    bool operator<(const El& el) const
    {
        return val > el.val;
    }
};

void solve(const int n, const int x)
{
    vector<int> arr;
    vector<int> edges;
    arr.reserve(n);
    edges.reserve(n);

    priority_queue<El> queue;

    for(int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        arr.push_back(x);
        edges.push_back(0);

        queue.emplace(i, x);
    }

    for(int i = 0; i < arr.size(); ++i)
    {
        if(i != 0)
        {
            if(arr[i] < arr[i - 1])
            {
                edges[i] += 1;
            }
        }
        if(i != arr.size() - 1)
        {
            if(arr[i + 1] > arr[i])
            {
                edges[i] += 1;
            }
        }
    }

    int num_islands = 1;
    int current_time = 0;
    while(num_islands != x && !queue.empty())
    {
        int num_edges_deleted = 0;
        El prev = queue.top();
        while(!queue.empty())
        {
            El next = queue.top(); 
            if(next.val != prev.val)
            {
                prev = next;
                break;
            }
            current_time = next.val;

            int num_edges = edges[next.index];
            if(num_edges > 0)
            {
                num_edges_deleted += num_edges - 1;
            }

            queue.pop();
        }

        num_islands += num_edges_deleted;
    }

    if(x == 0)
    {
        cout << current_time;
    }
    else if(num_islands != x)
    {
        cout << -1;
    }
    else 
    {
        cout << current_time;
    }

    cout << '\n';
}

int main(int argc, char *argv[])
{
    int t;
    cin >> t;

    for(int i = 0; i < t; ++i)
    {
        int n, x;
        cin >> n >> x;
        solve(n, x);
    }
}
