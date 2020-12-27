#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
    struct Node 
    {
        Node(int val, int prev, int next) : val{val}, prev{prev}, next{next} {}
        int val;
        int prev;
        int next;
    };

    vector<Node> vec;
    vec.reserve(100000);
    int s, b;
    while(cin >> s >> b)
    {
        if(s == 0 && b == 0)
        {
            break;
        }

        vec.clear();

        for(int i = 0; i < s; ++i)
        {
            vec.emplace_back(i + 1, i - 1, i + 1);
        }

        for(int _ = 0; _ < b; ++_)
        {
            int i, j;
            cin >> i >> j;

            const int prev_index = vec[i - 1].prev;
            const int next_index = vec[j - 1].next;

            if(prev_index < 0)
            {
                cout << '*';
            }
            else
            {
                vec[prev_index].next = next_index;
                cout << vec[prev_index].val;
            }

            cout << " ";

            if(next_index >= s)
            {
                cout << '*';
            }
            else
            {
                vec[next_index].prev = prev_index;
                cout << vec[next_index].val;
            }

            cout << endl;
        }

        cout << "-" << endl;
    }
}
