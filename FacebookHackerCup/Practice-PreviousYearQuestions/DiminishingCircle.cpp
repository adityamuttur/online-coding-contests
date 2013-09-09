#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>

using namespace std;

long long joseph (long long n, long long k) {
	if (n == 1LL) 
		return 0LL;
	if (k == 1LL) 
		return n - 1LL;
	if (k > n) 
		return (joseph(n - 1LL, k) + k) % n;

	long long cnt = n / k;
	long long res = joseph(n - cnt, k);
	res -= n % k;
	if (res<0LL)
		res += n;
	else
		res += res / (k - 1LL);

	return res;
}

int main(){
	int t;
	long long a, b;

	cin >> t;	
	for (int tt = 1; tt <= t; tt++){
		cin >> a >> b;
		b++;
		cout << joseph(a, b) + 1 << endl;
	}

	return 0;
}