#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

#define SIZE 100002
#define MIN(M, N) ((M) < (N) ? (M) : (N))
#define MAX(M, N) ((M) > (N) ? (M) : (N))

int main() {

	int T, N, k, arr[SIZE];
	bool flag;
	long long sum, min_range, min[SIZE];

	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		sum = flag = 0;
		for (int j = 0; j < N; j++) {
			scanf("%d", &arr[j]);
			if (arr[j] < 0)
				flag = 1;
			sum += arr[j];
		}
		if (!flag) {
			cout << sum << endl;
			continue;
		}

		min_range = min[0] = arr[0];
		for (int j = 1; j < N; j++) {
			min[j] = MIN(min[j-1]+arr[j], arr[j]);
			if(min[j] < min_range) {
				min_range = min[j];
			}
		}
		sum += (-2 * min_range);
		cout << sum << endl;
	}

	return 0;
}