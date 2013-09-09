#include <iostream>
#include <cmath>
#include <vector>

#define REP(i,n) 

using namespace std;

vector < pair<int,int> > num;
int a[10000002];
unsigned long long int c[4474][4474];

void precompute() {
	for(int i = 0; i < 10000001; i++)
		a[i] = i;

	c[0][0] = 1;

	for (int i = 0; i < 4474; i++) {
		c[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			if((c[i-1][j-1] + c[i-1][j]) <= 10000000) {
				c[i][j] = (c[i-1][j-1] + c[i-1][j]);
				if(a[c[i][j]] > (i))
					a[c[i][j]] = (i);
			}
			else {
				c[i][j]=100000000;
				break;
			}
		}
	}
}

void main2() {
	int S;
	cin >> S;
	pair <int, int> path;
	int ans = 10000000;

	num.clear();

	for(int i = 1; i <= (int)sqrt(S); i++) {
		if(S % i == 0) {
			path = make_pair(i,S/i);
			num.push_back(path);
		}
	}

	for(int i = 0; i < num.size(); i++)
		ans = min(ans, a[num[i].first] + a[num[i].second]);

	cout << ans << endl;
}

int main() {	
	precompute();
	int T, t;

	cin >> T;
	for(t = 0; t < T; t++) {
		printf("Case #%d: ", t+1);
		main2();
	}

	return 0;
}