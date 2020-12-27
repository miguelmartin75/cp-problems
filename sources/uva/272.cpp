#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	string line;

	char ch;
	bool b = true;
	while (cin.get(ch))
	{
		if (ch == '"')
		{
			b = !b;
			cout << (b ? "''" : "``");
			continue;
		}

		cout << ch;
	}
}