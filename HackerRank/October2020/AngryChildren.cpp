// https://www.hackerrank.com/contests/oct13/challenges/angry-children

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>

using namespace std;

#define SIZE 100005
#define MIN(M, N) ((M) < (N) ? (M) : (N))
int main() {

	int N, K, arr[SIZE];
	int unfairness;

	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr+N);
	unfairness = arr[K-1]-arr[0];
	for (int i = 1; K-1+i < N; i++) {
		unfairness = MIN(unfairness, arr[K+i-1] - arr[i]);
		// cout << arr[K+i-1] << " " << arr[i] << endl;
	}
	printf("%d\n", unfairness);

	return 0;
}

