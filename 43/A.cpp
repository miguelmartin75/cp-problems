#include <iostream>
#include <algorithm>
#include <map>

using score_map = std::map<std::string, int>;

int main(int argc, char *argv[])
{
    int n;
    std::cin >> n;
    std::cin.ignore();

    score_map scores;
    for(int i = 0; i < n; ++i)
    {
        std::string team;
        std::getline(std::cin, team);
        scores[team]++;
    }

    auto res = std::max_element(scores.begin(), scores.end(), [](score_map::value_type& x1, score_map::value_type& x2) { return x1.second < x2.second; });

    std::cout << res->first << '\n';
}
