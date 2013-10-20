#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>

using namespace std;

#define SIZE 1000

int get_solution(int N, int maxWt, int val[], int wt[]) {
    int  V[SIZE][SIZE];
    bool keep[SIZE][SIZE];
    vector < int > items;
    int temp;

    memset(keep, 0, SIZE*SIZE*sizeof(bool));
    memset(V, 0, SIZE*SIZE*sizeof(int)); 
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= maxWt; j++) {
            temp = val[i];
            V[i][j] = V[i-1][j];

            if (j - wt[i] < 0)
                continue;
            
            temp += V[i-1][j - wt[i]];
            if (temp > V[i-1][j]) {
                V[i][j] = temp;
                keep[i][j] = 1;
            }
        }
    }
    // for (int i = 1; i <= N; i++) {
    //     cout << val[i] << " " << wt[i] << endl;
    // }
    // for (int i = 0; i <= N; i++) {
    //     for (int j = 0; j <= maxWt; j++) {
    //         cout << V[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    for (int i = N, j = maxWt; i >= 0 && j >= 0; i--) {
        if (keep[i][j] == 1) {
            j -= wt[i];
            items.push_back(i);
        }
    }
    
    if (!items.empty())
        return V[N][maxWt];
    else
        return 0;
}

int main() {
    int W, T, N, val1, val2, val[SIZE], WT[SIZE];

    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%d %d", &N, &W);
        for (int j = 0; j < N; j++) {
            scanf("%d %d %d", &val1, &val2, &WT[j+1]);
            val[j+1] = val1*val2;
        }
        printf("%d\n", get_solution(N, W, val, WT));
    }

    return 0;
}