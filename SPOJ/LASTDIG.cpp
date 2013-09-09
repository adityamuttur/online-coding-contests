#include <iostream>
#include <cmath>

using namespace std;

int main () {
	long T, a, b, arr1[10] = {1, 1, 4, 4, 2, 1, 1, 4, 4, 2};

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> a >> b;
		a = a % 10;
		if (b == 0) {
			cout << "1\n";
			continue;
		}
		if (a == 0 || a == 1 || a == 5 || a == 6) {
			cout << a << endl;
			continue;
		}
		b = b % arr1[a];
		if (b == 0)
			b = arr1[a];
		cout << ((int)pow(a, b))%10 << endl;
	}
    return 0;
}
