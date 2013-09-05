#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
	int T, N, ans;
	long long S[5001], diff;

	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		for (int j = 0; j < N; j++)
			cin>>S[j];
		sort(S, S+N);
		diff = S[1] - S[0];
		for (int j = 2; j < N; j++) {
			if (S[j]-S[j-1] < diff)
				diff = S[j] - S[j-1];
		}
		cout<<diff<<endl;
	}
}