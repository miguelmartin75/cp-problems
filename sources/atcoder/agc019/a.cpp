#include <bits/stdc++.h>
using namespace std;

using int_type = long long;
long long MAX_VAL = std::numeric_limits<int_type>::max();

int_type solve(int_type n, int_type* coins, int_type* costs, unordered_map<int_type, int_type>& cache)
{
    if(n < 0) { return MAX_VAL; }
    if(n == 0) { return 0; }
    auto it = cache.find(n);
    if(it != cache.end()) return it->second;

    int_type result = MAX_VAL;
    for(int i = 0; i < 4; ++i)
    {
        int_type temp = solve(n - coins[i], coins, costs, cache);
        if(temp == MAX_VAL) continue;
        temp += costs[i];
        result = min(temp, result);
    }
    cache[n] = result;
    return result;
}

int_type solve(int_type n, int_type a, int_type b, int_type c, int_type d)
{
    n *= 4;
    int_type coins[] = { 1, 2, 4, 8 };
    int_type costs[] = { a, b, c, d };
    unordered_map<int_type, int_type> cache;
    return solve(n, coins, costs, cache);
}

int main(int argc, char *argv[])
{
    int_type q, h, s, d, n;
    cin >> q >> h >> s >> d >> n;

    cout << solve(n, q, h, s, d) << endl;
}
