#include <iostream>
#include <vector>
#include <utility>
#include <string>
using namespace std;

int main()
{
	int t;
	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		int d;
		cin >> d;

		using range = pair<int, int>;
		vector<pair<range, string>> names;
		names.reserve(d);

		for (int i = 0; i < d; ++i)
		{
			string name;
			int l, h;
			cin >> name >> l >> h;

			names.emplace_back(range{l, h}, name);
		}

		int p;
		cin >> p;

		for (int i = 0; i < p; ++i)
		{
			int price;
			cin >> price;

			bool valid = false;
			auto foundIt = names.end();
			for (auto it = names.begin(); it != names.end(); ++it)
			{
				if (price >= it->first.first && price <= it->first.second)
				{
					if (foundIt != names.end())
					{
						valid = false;
						break;
					}
					foundIt = it;
					valid = true;
				}
			}

			if (valid)
			{
				cout << foundIt->second << endl;
			}
			else
			{
				cout << "UNDETERMINED" << endl;
			}
		}
		if(i != t - 1)
			cout << endl;
	}
}