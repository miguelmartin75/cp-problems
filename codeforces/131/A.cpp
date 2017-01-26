#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
    string word;
    cin >> word;

    bool accident = true;
    string flipped = word;

    for(size_t i = 0; i < word.size(); ++i)
    {
        if(i != 0 && islower(word[i]))
        {
            accident = false;
        }

        flipped[i] = islower(word[i]) ? toupper(word[i]) : tolower(word[i]);
    }

    cout << (accident ? flipped : word) << endl;
}
