#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		int n;
		cin >> n;

		int age = -1;
		for (int j = 0; j < n; ++j)
		{
			int x;
			cin >> x;
			if (j == n / 2)
			{
				age = x;
			}
		}

		cout << "Case " << i + 1 << ": " << age << endl;
	}
}