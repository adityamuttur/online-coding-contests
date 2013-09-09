#include <iostream>

using  namespace std;

int main ()  {
	long long m[1000], w[1000], sum;
	int T, n;

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		sum = 0;
		for (int j = 0; j < n; j++)
			cin>>m[j];
		for (int j = 0; j < n; j++)
			cin>>w[j];
		sort(m, m+n);
		sort(w, w+n);

		for (int j = 0; j < n; j++)
			sum+=(m[j]*w[j]);
		cout << sum << endl;
	}

	return 0;
}
