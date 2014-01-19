#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

#define MOD 1000000007

typedef long long LL;

LL pow_mod(int a, int b) {

    LL x = 1, y = a;

    while(b > 0) {
        if(b % 2 == 1) {
            x = (x * y);
            if(x > MOD)
                x %= MOD;
        }
        y = (y * y);
        if(y > MOD)
                    y %= MOD;
                    b /= 2;
    }

    return x;
}

LL euler_inverse(int n) {

    return pow_mod(n, MOD-2);
}

LL get_solution(int n, int r) {

    vector<LL> f(n + 1,1);

    for (int i = 2; i <= n; i++)
        f[i]= (f[i-1]*i) % MOD;

    return (f[n]*((euler_inverse(f[r]) * euler_inverse(f[n-r])) % MOD)) % MOD;
}

int main() {

    int T;
    LL M, N;

    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%lld %lld", &M, &N);
        printf("%lld\n", get_solution(M+N-2, M-1));
    }

    return 0;
}
