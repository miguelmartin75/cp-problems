#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

using cache = map<int, int>;

int cycle_count(int n, cache& arr)
{
	if (n == 1) { return 1; }
	if (arr[n] != 0) { return arr[n]; }

	int next = n % 2 == 0 ? n / 2 : 3 * n + 1;
	int m = 1 + cycle_count(next, arr);
	arr[n] = m;
	return m;
}

int main()
{
	cache count;

	int i, j;
	while(cin >> i >> j)
	{
		int m = 0;

		cout << i << " " << j << " ";
		if (j < i) swap(i, j);

		for (int x = i; x <= j; ++x)
		{
			m = max(cycle_count(x, count), m);
		}

		cout << m << endl;
	}
}