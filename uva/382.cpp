#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	cout << "PERFECTION OUTPUT" << endl;
	for (;;)
	{
		int x;
		cin >> x;

		if (x == 0)
		{
			break;
		}

		int s = x == 1 ? 0 : 1;
		for (int i = 2; i * i <= x; ++i)
		{
			const int q = x / i;
			if (x == q*i)
			{
				s += i;
				if (i != q)
				{
					s += q;
				}
			}
		}

		cout.width(5);
		cout << x << "  ";
		if (s == x)
		{
			cout << "PERFECT";
		}
		else if (s < x)
		{
			cout << "DEFICIENT";
		}
		else
		{
			cout << "ABUNDANT";
		}
		cout << endl;
	}
	cout << "END OF OUTPUT" << endl;
}