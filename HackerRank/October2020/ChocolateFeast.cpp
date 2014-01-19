// https://www.hackerrank.com/contests/oct13/challenges/chocolate-feast

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {

    int T, N, C, M;
    int sweets, wrappers, new_sweets;

    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%d %d %d", &N, &C, &M);
        sweets = wrappers = N/C;
        while (wrappers >= M) {
            new_sweets = wrappers/M;
            wrappers = (wrappers%M) + new_sweets;
            sweets += new_sweets;
        }
        printf("%d\n", sweets);
    }

    return 0;
}
