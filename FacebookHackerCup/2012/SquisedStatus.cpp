#include <iostream>

#define num(s, i) (s[i] - '0')

using namespace std;

long long dig1(long long a, long long big) {
	if (a > big || a == 0)
		return 0;
	return 1;
}

long long dig2(long long a, long long b, long long big) {
	if ((b + 10 * a) >big || a == 0)
		return 0;
	return 1;
}

long long dig3(long long a, long long b, long long c, long long big) {
	if ((c + 10 * b + 100 * a) > big || a == 0)
		return 0;
	return 1;
}
int main() {
	long long big, N, len;
	string s;

	cin >> N;
	for (long long j = 0; j < N; j++) {
		cin >> big >> s;

		len = s.length();
		long long dp[len + 1];
		dp[len] = 1;
		for(long long i = len - 1; i >= 0; i--) {
			dp[i] =  dig1(num(s,i), big) ? dp[i + 1] : 0;
			dp[i] += i < len - 1 && dig2(num(s,i),num(s,i+1), big) ? dp[i + 2] : 0;
			dp[i] += i < len - 2 && dig3(num(s,i),num(s,i+1),num(s,i+2), big) ? dp[i + 3] : 0; 
			dp[i] %= 4207849484LL;
		}
		cout << "Case #" << j+1 << ": " << dp[0] << endl;
	}

	return 0;
}