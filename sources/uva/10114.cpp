#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int months;
	float down;
	float loan;
	int records;

	while (cin >> months >> down >> loan >> records)
	{
		if (months < 0)
		{
			break;
		}

		vector<float> rates;
		rates.resize(months + 1);
		for (int i = 0; i < records; ++i)
		{
			int m; 
			float r;
			cin >> m >> r;

			for (int i = m; i < rates.size(); ++i)
			{
				rates[i] = r;
			}
		}

		const float loan_per_month = loan / months;

		float val = (down + loan) * (1 - rates[0]);
		float owed = loan;

		int month = 0;
		while (val < owed && month < months)
		{
			++month;
			val = val * (1 - rates[month]);
			owed -= loan_per_month;
		}

		cout << month << " month";
		if (month != 1) cout << "s";
		cout << endl;
	}
}