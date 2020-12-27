#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	int t;
	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		int d, v, u;
		cin >> d >> v >> u;

		double x2 = u*u - v*v;
		if (x2 <= 0 || d == 0 || v == 0) 
		{
			cout << "Case " << i + 1 << ": can't determine" << endl;
			continue;
		}

		double x = sqrt(x2);
		double diff = abs(d*(u - x) / (x*u));
		cout << "Case " << i + 1 << ": ";
		cout << setprecision(3) << fixed << diff;
		cout << endl;
	}
}