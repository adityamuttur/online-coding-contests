#include <iostream>
#include <stdint.h>
#include <algorithm>

using namespace std;

int main() {
	uint64_t arr[10], M, check;
	int count, T, N;
	cin >> T;
	
	for (int i = 0; i < T; i++) {
		cin >> N >> M;
		check = 0;
		for (int j = 0; j < N; j++) {
			cin >> arr[j];
			check += arr[j];
		}
		if (check < M) {
			cout << -1 << endl;
			continue;
		}
		check = count = 0;
		sort(arr, arr+N, greater<uint64_t>());
		for (int j = 0; j < N; j++) {
			if (check < M) {
				check += arr[j];
				count++;
			}
		}
		cout << count << endl;
	}
	return 0;
} 