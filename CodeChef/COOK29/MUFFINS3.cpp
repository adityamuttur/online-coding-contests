#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
	int T;
	long N;

	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%ld", &N);
		N /= 2;
		N++;
		printf("%ld\n", N);
	}

	return 0;
}