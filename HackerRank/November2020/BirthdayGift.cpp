#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <cmath>

using namespace std;

int main() {

    int N, ball;
    double ans;

    scanf("%d", &N);
    ans = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d", &ball);
        ans += (((double)(ball))/2);
    }
    printf("%0.1lf\n", ans);

    return 0;
}
