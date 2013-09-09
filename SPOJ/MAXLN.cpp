#include <iostream>
#include <iomanip>

using namespace std;

int main () {
    long double k, a;
	int T;

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> k;
		a = (4*k*k) + 0.25;
		cout << fixed << showpoint << "Case "<< i+1<<": " << setprecision(2) << a << endl;
	}

	return 0;
}