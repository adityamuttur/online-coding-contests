#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

#define SIZE 1000000
#define MOD 1000000007

int powers[SIZE];

void precompute() {

    powers[0] = 1;
    for (int i = 1; i < SIZE; i++)
        powers[i] = (powers[i-1]*2)%MOD;
}

int main() {

    int T, N, temp;
    unsigned long long answer;
    
    precompute();

    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%d", &N);
        temp = N;
        answer = 1;
        while (temp > SIZE) {
            answer = (answer * powers[SIZE-1])%MOD;
            temp -= (SIZE-1);
        }
        answer = (answer * powers[temp])%MOD;
        answer--;
        printf("%llu\n", answer);
    }

    return 0;
}
