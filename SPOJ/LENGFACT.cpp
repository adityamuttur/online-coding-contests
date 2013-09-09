#include <iostream>
#include <cmath>

using namespace std;

int main() {
	long double n, a, Pi = 3.14159265358979323846264338327950288, e = 2.718281828459045235360287471352;
	long long a1;
	int T;

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;

		a = sqrt(2*Pi*n)*pow((n/e), n);
		a = .5*(log(2)+log(Pi)+log(n)) + n*(log(n)-log(e));
		a = a / log(10);
		a = a+1;
		a1 = (long long)a;
		if (n == 0 || n == 1)
			cout << "1" << endl;
		else
			cout << a1 << endl;
	}

	return 0;
}