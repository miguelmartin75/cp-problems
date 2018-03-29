#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
    string line;
    while(getline(cin, line))
    {
        istringstream iss{line};
        int num_words = 0;

        string word;
        while(iss >> word)
        {
            char prev = '\0';
            for(char ch : word) 
            {
                if(!isalpha(ch) && isalpha(prev))
                {
                    ++num_words;
                }
                prev = ch;
            }

            if(isalpha(prev)) { ++num_words; }
        }

        cout << num_words << endl;
    }
}
