#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using solution = pair<vector<int>, int>;

solution best(const vector<int>& tracks, int c, int n, solution s = { {}, 0 })
{
	solution b = s;
	int t = s.second;
	for (int i = c; i < tracks.size(); ++i)
	{
		if (t + tracks[i] > n) continue;

		solution temp_sol = s;
		temp_sol.first.emplace_back(tracks[i]);
		temp_sol.second += tracks[i];

		auto s = best(tracks, i + 1, n, temp_sol);
		if (s.second > b.second)
		{
			b = s;
		}
	}
	return b;
}

pair<vector<int>, int> best(const vector<int>& tracks, int n)
{
	solution ret = best(tracks, 0, n);
	return ret;
}

int main()
{
	int n;
	while (cin >> n)
	{
		int maxT;
		cin >> maxT;

		vector<int> tracks;
		tracks.reserve(maxT);
		for (int i = 0; i < maxT; ++i)
		{
			int x;
			cin >> x;
			tracks.emplace_back(x);
		}

		auto best = ::best(tracks, n);
		for (auto x : best.first)
		{
			cout << x << ' ';
		}
		cout << "sum:" << best.second << endl;
	}
}