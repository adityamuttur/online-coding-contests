#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>

#define SIZE 10000

using namespace std;

int main() {
    int T, N, K, answer, input[SIZE];
    string operation;
    
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%d %d %d", &N, &K, &answer);
        for (int j = 0; j < N; j++)
            scanf("%d", &input[j]);
        cin >> operation;
        if (K == 0) {
            cout << answer << endl;
            continue;
        }
        if (operation=="AND")
            for (int j = 0; j < N; j++)
                answer = answer & input[j];
        else if (operation=="OR") {
            for (int j = 0; j < N; j++)
                answer = answer | input[j];
        }
        else {
            if ((K % 2) != 0) {
                for (int j = 0; j < N; j++)
                    answer = (answer ^ input[j]);
            }
        }
        cout << answer << endl;
    }
    
    return 0;
}

