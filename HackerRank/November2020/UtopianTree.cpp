#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <cmath>

using namespace std;

int main() {

    int T, N, ans;

    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%d", &N);
        ans = 1;
        for (int i = 0; i < (N/2); i++) {
            ans *= 2;
            ans++;
        }
        if (N & 1)
            ans *= 2;
        printf("%d\n", ans);
    }

    return 0;
}
