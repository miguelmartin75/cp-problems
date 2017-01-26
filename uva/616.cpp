#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	for (;;)
	{
		int x;
		cin >> x;

		if (x == -1)
		{
			break;
		}

		int ans = -1;
		for(int y = sqrt(x) + 1; y >= 2; --y)
		{
			bool valid = true;
			int c = x;
			for (int i = 0; i < y; ++i)
			{
				// if we have one left for the monkey
				if (c % y != 1)
				{
					valid = false;
					break;
				}

				// go to the next iteration
				c = (c / y) * (y - 1);
			}

			// if there's no coconuts left over
			if (valid && c % y == 0)
			{
				ans = y;
				break;
			}
		}

		cout << x << " coconuts, ";
		if (ans == -1)
		{
			cout << "no solution";
		}
		else
		{
			cout << ans << " people and 1 monkey";
		}
		cout << endl;
	}
}