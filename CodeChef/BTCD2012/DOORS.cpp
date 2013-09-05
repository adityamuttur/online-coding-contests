#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main() {
	int T, N, ans;

	scanf("%d", &T);
	for (int p = 0; p < T; p++) {
		scanf("%d", &N);
		ans = (int)(sqrt(N));
		printf("%d\n", ans);
	}
	return 0;
}