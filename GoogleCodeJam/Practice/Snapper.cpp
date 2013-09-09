#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int T, N, K;

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N >> K;
		K++;
		K = K % (int(pow(2, N)));
		if (K == 0)
			cout << "Case #" << i+1 << ": ON\n";
		else
			cout << "Case #" << i+1 << ": OFF\n";
	}

	return 0;
}