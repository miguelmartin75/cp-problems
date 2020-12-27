#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

template <class F, class G>
double newton(F f, G deriv)
{
	if (f(0) == 0) return 0;

	double x = 0.5;
	while (true)
	{
		double fx = f(x);
		if (fabs(fx) < 1e-6) {
			break;
		}

		double nextX = x - fx / deriv(x);
		if (isnan(x) || fabs(nextX - x) <= 1e-7) {
			break;
		}
		x = nextX;
	}
	return x;
}

int main()
{
	int p, q, r, s, t, u;
	int it = 0;
	while (cin >> p >> q >> r >> s >> t >> u)
	{
		cout << p << " " << q << " " << r << " " << s << " " << t << " " << u << endl;
		auto f = [&](double x) -> double {
			return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
		};
		auto deriv = [&](double x) -> double {
			return -p*exp(-x) + q*cos(x) - r*sin(x) + s / (cos(x) * cos(x)) + 2 * t * x;
		};

		double x = newton(f, deriv);

		if (x >= 0 && x <= 1)
		{
			cout << setprecision(4) << fixed << x << endl;
		}
		else
		{
			cout << "No solution" << endl;
		}
	}
}