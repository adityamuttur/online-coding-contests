#include <iostream>
#include <math.h>

using namespace std;

int main () {
	long a, T, count, k, temp;

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> a;
		count = 0;
		k = 1;
		while (1) {
			temp = pow(5,k);
			if (a/temp == 0)
				break;
			count += (a/temp);
			k++;
		}
		cout << count << endl;
	}

	return 0;
}
