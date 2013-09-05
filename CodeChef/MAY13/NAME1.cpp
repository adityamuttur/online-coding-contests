#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

inline void checkAlpha(int checkArray[26]) {
	int temp;
	char str[40002];

	cin >> str;
	temp = strlen(str);
	for (int j = 0; j < temp; j++)
		checkArray[str[j]-'a']++;
}

int main() {
	int T, N, parents[26], children[26];
	bool flag;

	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		memset(parents, 0, 26*sizeof(int));
		memset(children, 0, 26*sizeof(int));
		checkAlpha(parents);
		checkAlpha(parents);
		cin >> N;
		for (int k = 0; k < N; k++)
			checkAlpha(children);
		flag = 1;
		for (int j = 0; j < 26; j++)
			if (parents[j] < children[j]) {
				printf("NO\n");
				flag = 0;
				break;
			}
		if (flag)
			printf("YES\n");
	}

	return 0;
} 