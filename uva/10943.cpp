#include <iostream>
#include <vector>
#include <map>
using namespace std;

const int M = 1000000;

int how_many(int n, int k)
{
	if (k == 0) return 0;

	vector<int> prev_k;
	prev_k.resize(n + 1, 1);
	vector<int> curr_k = prev_k;
	for (int i = 2; i <= k; ++i)
	{
		for (int i = 1; i < curr_k.size(); ++i)
		{
			curr_k[i] = (curr_k[i - 1] + prev_k[i]) % M;
		}

		swap(curr_k, prev_k);
	}
	return prev_k.back();
}

int main()
{
	int n, k;
	while (cin >> n >> k)
	{
		if (n == 0 && k == 0) break;
		cout << how_many(n, k) << endl;
	}
}