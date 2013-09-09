#include <iostream>
#include <climits>

using namespace std;

int main () {
	int N, R, pos;
	long arr[101][50], big[100], t2, large;
	double t1;

	while (1) {
		cin >> N >> R;
		if (N == 0 && R == 0)
			break;
		for (int i = 0; i <= R; i++) {
			for (int j = 0; j < N; j++) {
				cin>>arr[i][j];
				if (i == 0)
					arr[i][j] *= 10;
			}
		}
		large = 0;
		pos = 1;
		for (int i = 1; i <= R; i++) {
			big[i-1] = LONG_MAX;
			for (int j = 0; j < N; j++) {
				if (arr[i][j] == 0)
					continue;
				t1 = (double(arr[0][j]) / arr[i][j]);
				t2 = long(t1);
				if (t2 < big[i-1])
					big[i-1] = t2;
			}
			if (big[i-1] > large) {
				large =  big[i-1];
				pos = i;
			}
		}
		cout << pos << " " << large << endl;
	}
	return 0;
}