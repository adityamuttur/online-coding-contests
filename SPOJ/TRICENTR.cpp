#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main () {
	long double a, b, c, h1, h2, h3, area, R, HO, HG;
	int T;

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> a >> h1 >> h2 >> h3;
		area = R = HO = HG = 0;
		h1 *= 3;
		h2 *= 3;
		h3 *= 3;
		area = 0.5*a*h1;
		b = 2.0*area/h2;
		c = 2.0*area/h3;
		R = (a*b*c) / (4*area);
		HO = sqrt(fabs((9*R*R) - ((a*a) + (b*b) + (c*c))));
		HG = 2.0 * HO / 3;
		cout << fixed << showpoint << setprecision(3) << area << " " << HG << endl;
	}

	return 0;
}

