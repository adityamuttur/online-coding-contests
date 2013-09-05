#include <iostream>

using namespace std;

int main() {
	int t, n, x, i, small, num, a[102];
	long int sum;
	
	cin >> t;
	while(t--) {
		cin >> n >> x;
		sum=0;
		for(i = 0; i < n; i++) {
			cin >> a[i];
			sum += a[i];
		}
		small = a[0];
		for(i = 0; i < n; i++) {
			if(a[i] < small)
				small = a[i];
		}
		num = sum / x;
		if(sum - (num * x) >= small)
			cout << -1 << endl;
		else
			cout << num << endl;
	}
	return 0;
}