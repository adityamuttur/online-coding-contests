#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

#define SIZE 1000000

using namespace std;

typedef unsigned long long ULL;
typedef long long LL;

int main() {

    int T, N, a[SIZE], temp;
    ULL ans = 1;

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        for (int j = 0; j < N; j++)
            cin >> temp;
        ans = (((N)*(N-(1LL)))/(2LL));
        cout << ans << endl;
    }

    return 0;
}
