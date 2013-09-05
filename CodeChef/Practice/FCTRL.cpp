#include <iostream>

using namespace std;

int main() {
	int count, n, T, temp;

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		temp = 5;
		count = 0;
		while (n / temp > 0) {
			count += (n/temp);
			temp *= 5;
		}
		cout << count << endl;
	}

	return 0;
}