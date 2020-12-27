#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void solve(const vector<int>& arr)
{
	vector<pair<int, int>> dp;

	int maxIndex = -1;
	pair<int, int> maxEnd{0, -1};

	for (int i = 0; i < arr.size(); ++i)
	{
		pair<int, int> maxLocal{1, i};
		for (int j = 0; j < dp.size(); ++j)
		{
			if (arr[i] > arr[j] && maxLocal.first < 1 + dp[j].first)
			{
				maxLocal.first = 1 + dp[j].first;
				maxLocal.second = j;
			}
		}

		dp.push_back(maxLocal);
		if (maxEnd.first < maxLocal.first)
		{
			maxIndex = i;
			maxEnd = maxLocal;
		}
	}

	cout << maxEnd.first << endl;

	if (maxIndex != -1)
	{
		cout << "-" << endl;

		stack<int> elements;
		int current = maxIndex;
		while(true)
		{
			elements.push(arr[current]);
			
			if (dp[current].second == current)
			{
				break;
			}

			current = dp[current].second;
		}

		while (!elements.empty())
		{
			cout << elements.top() << endl;
			elements.pop();
		}
	}
}

int main()
{
	vector<int> elements;
	int x;
	while (cin >> x)
	{
		elements.push_back(x);
	}

	solve(elements);
}