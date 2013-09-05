#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <algorithm>

#define x first
#define y second

using namespace std;

int main() {
	int T, N, arr[10004], a[2][100], p, low, temp;

	cin>>T;

	for (int i = 0; i < T; i++) {
		cin>>N;
		for (int j = 0; j < 100; j++)
			temp = p = a[0][j] = a[1][j] = 0;

		for (int j = 0; j < 10004; j++)
			arr[j] = 0;

		for (int j = 0; j < N; j++) {
			cin>>temp;
			arr[temp]++;
			a[0][j] = temp;
			a[1][j] = arr[temp];
		}

		sort(arr, arr+10004);
		low = 99999999;
		p=N-1;
		for(int p = 0; p < N; p++) {
			if (low > a[0][p] && arr[10003] == a[1][p])
				low = a[0][p];
		}

		cout << low << " " << arr[10003] << endl;
	}
	return 0;
}