#include <iostream>

using namespace std;

int main () {
	long long n, ans, inp;
	int T;

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		ans = 0;
		for (int j = 0; j < n; j++) {
			cin >> inp;
			ans = (ans+inp)%n;
		}
		if (ans == 0)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}