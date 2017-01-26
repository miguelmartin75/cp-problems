#include <iostream>
using namespace std;

int main()
{
	const int offset = 7;

	char ch;
	while(cin.get(ch))
	{
		if (!isspace(ch)) 
		{
			ch -= offset;
		}
		cout << ch;
	}
}