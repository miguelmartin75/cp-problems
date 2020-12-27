#include <iostream>
using namespace std;

int main()
{
	int n, k;
	while (cin >> n >> k)
	{
		int total = 0;
		int lo_buds = 0;
		while (n > 0)
		{
			total += n;

			int num_buds = n + lo_buds;
			int new_cigs = num_buds / k;

			n = new_cigs;
			lo_buds = num_buds % k;
		}

		cout << total << endl;
	}
}