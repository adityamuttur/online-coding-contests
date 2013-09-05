#include <iostream>
#include <stdio.h>
#include <string>
#include <map>
#include <cmath>

using namespace std;

int main() {
	int T, ans;
	string s, parse = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	map <char, int> m;

	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		m.clear();
		ans = 0;

		cin >> s;
		for (int j = 0; j < s.length(); j++)
			m[s[j]]++;
		for (int k = 0; k < parse.length(); k++)
			ans += (int)(ceil( ((double)(m[parse[k]]))/2 ));
		printf("%d\n", ans);
	}

	return 0;
}
