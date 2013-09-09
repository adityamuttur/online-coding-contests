#include <iostream>

using namespace std;

int main () {
	int T, a = 0, b = 0;

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> a >> b;

		if (a == b || (a - b) == 2) {
			if (a % 2 == 0)
				cout << a+b << endl;
			else
				cout << a+b-1 << endl;
		}
		else 
		{
			cout << "No Number" << endl;
			continue;
		}
	}

	return 0;
}