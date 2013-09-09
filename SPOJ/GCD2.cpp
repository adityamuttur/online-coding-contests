#include <iostream>
#include <string>

using namespace std;

int gcd(int a, int b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a%b);
}

int val(char str[], int len, int a) {
	int temp = 0;

	for (int i = 0; i < len; i++)
		temp = ((temp * 10) + (str[i] - '0')) % a;

	return temp;
}

int main () {
	int a, b, T;
	char temp[252];

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> a >> temp;

		if (a == 0)
			cout << temp << endl;
		else {
			b = val(temp, strlen(temp), a);
			cout << gcd(a, b) << endl;
		}
	}
	return 0;
}