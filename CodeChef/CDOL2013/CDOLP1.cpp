#include <iostream>
#include <algorithm>

#define MAX(M, N) (M>N?M:N)

using namespace std;

int main() {
	int T, N, F, S, A, B, friends[10000], val, threat, chk1, chk2, ctr, ctrVal;

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N >> S >> F;
		for (int q = 1; q <= N; q++)
			friends[q] = q;
		for (int j = 0; j < F; j++) {
			cin >> A >> B;
			chk1 = friends[A];
			chk2 = friends[B];
			for (int p = 1; p <= N; p++)
				if(friends[p] == chk1 || friends[p] == chk2)
					friends[p] = A;
		}
		val = friends[S];
		for (int l = 1; l <= N; l++) {
			if (friends[l] == val)
				friends[l] = 0;
		}
		sort(friends, friends+N);
		threat = 0;

		for (int w = 1; w <= N; w++) {
			if (friends[w] == 0)
				continue;
			val = friends[w];
			ctr = 0;
			while(friends[w] == val && w <= N) {
				ctr++;
				w++;
			}
			w--;
			threat = MAX(threat, ctr);
		}
		cout << threat << endl;
	}

	return 0;
}