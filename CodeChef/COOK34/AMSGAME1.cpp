#include <iostream>
#include <stdint.h>

using namespace std;

uint64_t HCF(uint64_t a, uint64_t b) {
	if (a == 0)
		return b;
	return HCF(b%a, a);
}

int main() {
	uint64_t ans, val;
	int T, N;

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		cin >> val;
		ans = val;
		for (int j = 1; j < N; j++) {
			cin >> val;
			ans = HCF(ans, val);
		}
		cout << ans << endl;
	}
	return 0;
}