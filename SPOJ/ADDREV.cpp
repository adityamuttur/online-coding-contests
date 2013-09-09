#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int T, m, n, k;
	stringstream ss;
	string s1, s2, s3;
	char arr2[11], arr1[11];

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> m >> n;

		ss << m;
		s1 = ss.str();
		reverse(s1.begin(), s1.end());
		ss.str("");

		ss << n;
		s2 = ss.str();
		reverse(s2.begin(), s2.end());
		ss.str("");

		k = s1.length() - 1;
		arr1[k+1] = '\0';
		while (k >= 0) {
			arr1[k] = s1[k];
			k--;
		}

		k = s2.length()-1;
		arr2[k+1] = '\0';
		while (k >= 0) {
			arr2[k] = s2[k];
			k--;
		}

		ss << (atoi(arr1) + atoi(arr2));
		s3 = ss.str();
		reverse(s3.begin(), s3.end());
		ss.str("");

		k = s3.length()-1;
		arr2[k+1] = '\0';
		while (k >= 0) {
			arr2[k] = s3[k];
			k--;
		}

		cout << atoi(arr2) << endl;
		s1.erase();
		s2.erase();
		s3.erase();
	}

	return 0;
}