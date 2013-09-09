#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	int T, n;
	long long x[800], y[800], sum;

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		for (int j = 0; j < n; j++)
			cin >> x[j];
		for (int j = 0; j < n; j++)
			cin >> y[j];
		sort(x, x+n);
		sort(y, y+n);
		sum = 0;
		for (int j = 0; j < n; j++)
			sum += (x[j] * y[n-j-1]);
		cout << "Case #" << i+1 << ": " << (sum) << endl;
	}

	return 0;
}