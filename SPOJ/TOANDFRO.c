#include <stdio.h>
#include <ctype.h>

int main() {
	int num = 1, i,j, k, l;
	char arr[20][20], ch;

	while(num != 0) {
		scanf("%d", &num);
		if (num == 0)
			break;
		for (i = 0; ; i++) {
			for(j = 0; j < num; j++) {
				scanf("%c", &ch);
				while ((i%2) == 0) {
					arr[i][j] = ch;
					if (ch == '\n'||ch == '\0')
						break;
					if(isalpha(ch))
						break;
					else
						continue;
				}
				while(i % 2 == 1) {
					arr[i][num - j - 1] = ch;
					if (ch == '\n'||ch == '\0')
						break;
					if(isalpha(ch))
						break;
					else
						continue;
				}
				if (!isalpha(ch))
					break;
			}
			if (!isalpha(ch))
				break;
		}
		for (k = 0; k < num; k++) {
			for(l = 0; l < i; l++) {
				printf("%c", arr[l][k]);
				arr[l][k] = 0;
			}
		}
		printf("\n");
	}

	return 0;
}