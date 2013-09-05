#include <iostream>

using namespace std;

int main() {
	long long int m, n, fib1 = 0, fib2 = 1, temp, count =0;

	while(1) {
		cin >> m >> n;
		if (m == 0 && n == 0)
			break;
		count = 0;
		while (fib1 < n) {
			temp = fib2;
			fib2 += fib1;
			fib1 = temp;
			if (fib1 > m && fib1 < n)
				count++;
		}
		cout << count << endl;
	}

	return 0;
}