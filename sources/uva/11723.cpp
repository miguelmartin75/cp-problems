#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	for (int i = 0; ; ++i)
	{
		int r, n;
		cin >> r >> n;

		if (n == 0)
		{
			break;
		}

		int ans = ceil(static_cast<double>(r) / n - 1);
		if (ans > 26)
		{
			cout << "Case " << i + 1 << ": impossible" << endl;
			continue;
		}

		cout << "Case " << i + 1 << ": " << ans << endl;
	}
}