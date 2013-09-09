#include <iostream>

using namespace std;

int main () {
	int T;
	long long n, ans;

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin>>n;
		if (n%2 != 0)
			ans = (n+1) * ((2*n*n) + (3*n) - 1) / 8;
		else
			ans = n * (n+2) * (2*n+1) / 8;
		cout << ans << endl;
	}

	return 0;
}