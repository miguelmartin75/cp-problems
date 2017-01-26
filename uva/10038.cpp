#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

int main()
{
	string line;
	while (getline(cin, line))
	{
		stringstream ss{line};

		size_t n;
		ss >> n;

		vector<bool> b(n - 1, true);

		int curr, prev;
		ss >> prev;
		while(ss >> curr)
		{
			const int diff = abs(curr - prev);
			if(diff > 0 && diff < n) b[diff - 1] = false;
			prev = curr;
		}

		cout << (accumulate(b.begin(), b.end(), 0) == 0 ? "Jolly" : "Not jolly") << endl;
	}
}