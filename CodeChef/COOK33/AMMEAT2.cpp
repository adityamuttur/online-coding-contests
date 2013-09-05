#include <iostream>

using namespace std;

int main() {
	int T, K, N;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> N >> K;

		if (N == 1 && K == 1) {
			cout << 1 << endl;
			continue;
		}
		if (K > (N/2))
			cout << -1 << endl;
		else {
			for (int j = 1; j <= K; j++) {
				if (j != 1)
					cout << " ";
				cout << j*2;
			}
			cout << endl;
		}
	}
	return 0;
}
