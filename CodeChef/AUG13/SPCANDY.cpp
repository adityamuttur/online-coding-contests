#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	unsigned long long T, N, K, students, teacher;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N >> K;
		if (N == 0) {
			students = 0;
			teacher = 0;
		}
		else if (K == 0) {
			students = 0;
			teacher = N;
		}
		else {
			students = N/K;
			teacher = N%K;
		}
		cout << students << " " << teacher << endl;
	}

	return 0;
}