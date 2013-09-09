#include <iostream>

using namespace std;

int main () {
	string a;
	char op;
	long long p, q;
	int T, num;

	cin >> T;
	for (int i = 0; i < T; i++) {
		num = 0;
		while (1) {
			cin >> a;
			if (a == "=")
				break;
			if (isdigit(a[0]) && num == 0)
				p = atoi(a.c_str());
			else if (isdigit(a[0]) && num == 2)
				q = atoi(a.c_str());
			else
				op = a[0];

			num++;
			if (num == 3) {
				num = 1;
				switch(op) {
					case '+': 
						p += q;
						break;
					case '-': 
						p -= q;
						break;
					case '*': 
						p *= q;
						break;
					case '/': 
						p /= q;
						break;
				}
			}
		}
		cout << p << endl;
	}

	return 0;
}