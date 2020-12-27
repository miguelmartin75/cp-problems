#include <iostream>
#include <vector>
using namespace std;

using int_type = long long;
using poly = std::vector<int_type>;

int_type eval(const poly& p, int_type n) 
{
	int_type res = 0;
	int_type curr_p = 1;
	for (auto& x : p)
	{
		res += x * curr_p;
		curr_p *= n;
	}
	return res;
}

int_type solve(const poly& poly, int_type d, int_type k)
{
	int_type res = 0;
	for (int i = 1; ; i++)
	{
		int coeff = (i * (i + 1)) / 2;
		int m = coeff * d;

		if (k <= m)
		{
			return eval(poly, i);
		}
	}
	return res;
}

int main()
{
	int t;
	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		int_type n;
		cin >> n;

		poly poly;
		poly.reserve(n);

		for (int i = 0; i <= n; ++i)
		{
			int x;
			cin >> x;
			poly.emplace_back(x);
		}

		int_type d, k;
		cin >> d >> k;

		cout << solve(poly, d, k) << endl;
	}
}