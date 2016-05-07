#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(int argc, char *argv[])
{
    cin.sync_with_stdio(false);

    int n;
    cin >> n;

    // language -> count
    map<int, int> langs;

    for(int i = 0; i < n; ++i)
    {
        int lang;
        cin >> lang;
        langs[lang]++;
    }

    int m;
    cin >> m;
    
    vector<int> audio;

    for(int i = 0; i < m; ++i)
    {
        int x;
        cin >> x;
        audio.emplace_back(x);
    }


    int max_audio = -1;
    int max_sub = -1;
    int max_movie = -1;

    for(int i = 0; i < m; ++i)
    {
        int sub;
        cin >> sub;

        const int a = audio[i];

        const int count_a = langs[a];
        const int count_sub = langs[sub];

        bool should_update = false;
        if(count_a > max_audio)
        {
            should_update = true;
        }
        else if(count_a == max_audio && count_sub > max_sub)
        {
            should_update = true;
        }

        if(should_update)
        {
            max_movie = i + 1;
            max_audio = count_a;
            max_sub = count_sub;
        }
    }

    cout << max_movie << endl;
}
