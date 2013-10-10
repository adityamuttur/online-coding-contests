#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

#define SIZE 100000
#define PRIME 99991
#define MAX(M, N) (M>N?M:N)
#define MIN(M, N) (M<N?M:N)

using namespace std;

struct Music {
	uint64_t B, L;
};

Music minSongs[SIZE];
uint64_t sumOfRest;
int uniqueBands;

inline bool myGreater(const Music& a, const Music& b) {
	return a.L > b.L;
}

inline void hashAndAdd(uint64_t &B, uint64_t &L) {
	int index = B % PRIME;

	for (int i = index; i < SIZE; i++) {
		if (minSongs[i].B == B) {
			sumOfRest += MAX(minSongs[i].L, L);
			minSongs[i].L = MIN(minSongs[i].L, L);
			return;
		}
		if (minSongs[i].B == 0) {
			minSongs[i].B = B;
			minSongs[i].L = L;
			uniqueBands++;
			return;
		}
	}

	for (int i = 0; i < index; i++) {
		if (minSongs[i].B == B) {
			sumOfRest += MAX(minSongs[i].L, L);
			minSongs[i].L = MIN(minSongs[i].L, L);
			return;
		}
		if (minSongs[i].B == 0) {
			minSongs[i].B = B;
			minSongs[i].L = L;
			uniqueBands++;
			return;
		}
	}
}

int main() {
	uint64_t T, N, B, L, ans;

	scanf("%llu", &T);

	for (int i = 0; i < T; i++) {
		scanf("%llu", &N);
		memset(minSongs, 0, SIZE*sizeof(Music));
		ans = 0;
		uniqueBands = 0;
		sumOfRest = 0;

		for (int j = 0; j < N; j++) {
			scanf("%llu%llu", &B, &L);
			hashAndAdd(B, L);
		}
		sort(minSongs, minSongs+SIZE, myGreater);
		for (int j = uniqueBands-1; j >= 0; j--)
			ans += minSongs[j].L*(uniqueBands-j);
		ans += sumOfRest*uniqueBands;
		printf("%llu\n", ans);
	}

	return 0;
}