#include <iostream>
#include <iterator>
using namespace std;

int main()
{
	int t;
	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		int counts[10] = {};

		int x;
		cin >> x;
		
		for (int i = 1; i <= x; ++i)
		{
			int y = i;
			do
			{
				int d = y % 10;
				counts[d]++;
				y /= 10;
			} while (y > 0);
		}

		for (auto it = begin(counts); it != end(counts); ++it)
		{
			cout << *it;
			if (it + 1 != end(counts))
			{
				cout << ' ';
			}
		}
		cout << endl;
	}
}