#include <cstdio>
#include <cstring>

#define SIZE 101

using namespace std;

int main() {
    int level, power, soint[SIZE], sofloat[SIZE], M, N, T, difference, chakra;

    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &N, &M);

        memset(soint, 0, SIZE*sizeof(int));
        memset(sofloat, 0, SIZE*sizeof(int));

        for(int i = 0; i < N; i++) {
            scanf("%d %d", &power, &level);
            soint[level] += power;
        }

        for(int i = 0; i < M; i++) {
            scanf("%d %d", &power, &level);
            sofloat[level] += power;
        }

        chakra = difference = 0;
        for (int i = 0; i < SIZE; i++) {
            difference = soint[i] - sofloat[i];
            if (difference < 0)
                chakra += (-difference);
        }
        printf("%d\n", chakra);
    }

    return 0;
}
