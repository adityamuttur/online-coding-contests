#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

#define SIZE 1000000
#define MOD 1000000007

int main() {

    int T, K, N, A[SIZE], key, pos;

    scanf("%d", &T);
    for (int i = 0; i < T; i++) {

        scanf("%d", &N);
        for (int j = 0; j < N; j++)
            scanf("%d", &A[j]);
        scanf("%d", &K);

        key = A[K-1];
        pos = 0;
        for (int j = 0; j < N; j++)
            if (A[j] < key)
                pos++;

        // Make it 1-indexed
        pos++;
        printf("%d\n", pos);
    }

    return 0;
}
