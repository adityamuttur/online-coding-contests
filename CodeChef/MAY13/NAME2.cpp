#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;

inline bool checkSubstring(string &pattern, string &text) {
	int textCounter = 0;
	int patternCounter = 0;

	while(textCounter < text.length() && patternCounter < pattern.length()) {
		if (text[textCounter] == pattern[patternCounter]) {
			textCounter++;
			patternCounter++;
			//cout << textCounter << " " << patternCounter << endl;
		}
		else
			textCounter++;
	}

	if (patternCounter == pattern.length())
		return 1;
	else
		return 0;
}

int main() {
	int T;
	string M, W;
	bool flag;

	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		cin >> M >> W;
		if (M.length() < W.length())
			flag = checkSubstring(M, W);
		else
			flag = checkSubstring(W, M);

		if (flag)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}