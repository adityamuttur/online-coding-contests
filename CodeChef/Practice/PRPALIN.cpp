#include<iostream>
#include<stdlib.h>
#include<stdint.h>
#include<unistd.h>
#include<cmath>
#include<cstdio>
#include<cstring>
#define LIMIT 1100001
using namespace std;

int primes[LIMIT], no_primes = 0;

void gen_prime() {
    int upperBound = LIMIT, upperBoundSquareRoot = (int) sqrt ((double) upperBound);
    bool *isComposite = new bool[upperBound + 1];
    no_primes = 0;
    memset (isComposite, 0, sizeof (bool) * (upperBound + 1));
    for (int m = 2; m <= upperBoundSquareRoot; m++) {
        if (!isComposite[m]) {
            primes[no_primes++] = m;
            for (int k = m * m; k <= upperBound; k += m)
                isComposite[k] = true;
        }
    }
    for (int m = upperBoundSquareRoot; m <= upperBound; m++)
        if (!isComposite[m]) {
            primes[no_primes++] = m;
        }
    delete[]isComposite;
}

bool is_palindrome(int a) {
    char str[100];
    int len;

    sprintf(str, "%d", a);
    len = strlen(str);
    for (int i = 0; i < len/2; i++) {
        if (str[i] != str[len-i-1])
            return false;
    }
    return true;
}

int main() {
    int N, pos;

    cin >> N;

    gen_prime();
    
    for (int i = 0; i < no_primes; i++) {
        if (primes[i] >= N && is_palindrome(primes[i])) {
            cout << primes[i] << endl;
            return 0;
        }
    }
    
    return 0;
}
