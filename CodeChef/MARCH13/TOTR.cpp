#include <iostream>
#include <ctype.h>
#include <algorithm>
#include <map>

using namespace std;

int main() {
	int N, T;
	map<char, char> m;
	string str;
	cin >> T >> str;
	for (int i = 0; i < 26; i++) {
		m['a'+i] = str[i];
		m['A'+i] = toupper(str[i]);;
	}
	for (int i = 0; i < T; i++) {
		cin >> str;
		for (int p = 0; p < str.length(); p++) {
			if (isalpha(str[p]))
				cout << m[str[p]];
			else if (str[p] == '_')
				cout << " ";
			else
				cout << str[p];
		}
		cout << endl;
	}

	return 0;
}