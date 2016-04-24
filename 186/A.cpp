#include <iostream>
#include <string>

bool same_genome(const std::string& s1, const std::string& s2)
{
    if(s1.size() != s2.size())
    {
        return false;
    }

    int amount_out_of_order = 0;
    for(int i = 0; i < s1.size(); ++i)
    {
        char ch1 = s1[i];
        char ch2 = s2[i];

        if(ch1 != ch2)
        {
            ++amount_out_of_order;

            if(amount_out_of_order > 2)
            {
                return false;
            }
        }
    }

    int c1s[128] = {};
    int c2s[128] = {};

    for(auto ch : s1) c1s[ch]++;
    for(auto ch : s2) c2s[ch]++;

    for(int i = 0; i < 128; ++i)
    {
        if(c1s[i] != c2s[i])
        {
            return false;
        }
    }

    return true;
}

int main(int argc, char *argv[])
{
    std::string s1, s2;
    std::cin >> s1 >> s2;

    std::cout << (same_genome(s1, s2) ? "YES" : "NO") << '\n';
}
