#include <iostream>
#include <map>
using namespace std;

int main()
{
	for(int c = 0; ; ++c)
	{
		int z, i, m, l;
		cin >> z >> i >> m >> l;

		if (z == 0 && i == 0 && m == 0 && l == 0)
		{
			break;
		}

		int ans;
		map<int, int> pos;

		int current = l;
		int x = 0;
		pos[current] = 0;
		while (true)
		{
			++x;

			current = (z * current + i) % m;

			auto it = pos.find(current);
			if (it != pos.end())
			{
				ans = x - it->second;
				break;
			}

			pos.emplace(current, x);
		}

		cout << "Case " << c + 1 << ": " << ans << endl;
	}
}