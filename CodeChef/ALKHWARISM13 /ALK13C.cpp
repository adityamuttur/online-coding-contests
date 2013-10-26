#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>

typedef long long LL;

#define gx getchar//_unlocked
void scan( int &n ) {
	int sign = 1; n = 0;
	char c = gx();
	while( c < '0' || c > '9' ) {
		if( c == '-' ) sign = -1;
		c = gx();
	}
	while( c >= '0' && c <= '9' ) n = (n<<3) + (n<<1) + c - '0', c = gx();
	n = n * sign;
}

#define px putchar//_unlocked
void print(int n) {
	if(n<0) {
		n=-n;
		px('-');
	}
	int i=10;
	char o[10];
	do {
		o[--i] = (n%10) + '0'; n/=10; 
	}while(n);
	do {
		px(o[i]);
	}while(++i<10);
}

#define ps putchar/*_unlocked*/(' ');
#define pn putchar/*_unlocked*/('\n');

#define SIZE 1000000
#define RANGE 100000
using namespace std;

int main() {

	int T, N, X, Y, X_count, Y_count, ans;
	bool X_grid[SIZE], Y_grid[SIZE];
	scan(T);

	for (int i = 0; i < T; i++) {
		scan(N);
		memset(X_grid, 0, SIZE*sizeof(bool));
		memset(Y_grid, 0, SIZE*sizeof(bool));
		X_count = Y_count = 1;

		for (int j = 0; j < N; j++) {
			scan(X);
			scan(Y);
			if (!X_grid[X+RANGE]) {
				X_grid[X+RANGE] = 1;
				X_count++;
			}
			if (!Y_grid[Y+RANGE]) {
				Y_grid[Y+RANGE] = 1;
				Y_count++;
			}
		}
		ans = X_count*Y_count;
		print(ans);
		pn;
	}

	return 0;
}