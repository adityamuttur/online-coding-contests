#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <cstring>
#include <string>

using namespace std;

#define SIZE 1000000
#define MOD 1000000007

typedef unsigned long long ULL
typedef long long LL

LL convert_to_int(char *str, bool key) {

    int length = strlen(str);
    LL answer = 0;

    for (int i = 0; i < length; i++)
        answer = ((answer*10) + (str[i] - '0')) % (MOD-key);

    return answer;
}

LL get_solution(LL base, LL exp) {

    LL res = 1;

    while(exp > 0) {
        if(exp % 2 == 1)
            res = (res * base) % MOD;

        base = (base * base) % MOD;
        exp /= 2;
    }

    return res % MOD;
}

int main() {

    int T;
    char str[SIZE];
    LL A, B;

    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%s", str);
        A = convert_to_int(str, 0);

        scanf("%s", str);
        B = convert_to_int(str, 1);

        cout << get_solution(A, B) << endl;
    }

    return 0;
}
