#include <iostream>
#include <cmath>
#include <algorithm>

#define MAX 100001

using namespace std;

int main() {
    int T, N, K, tot_sum, start, stop, chk_sum, a[200];
    
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> N >> K;
        tot_sum = chk_sum = 0;
        for (int j = 0; j < N; j++) {
            cin >> a[j];
            tot_sum += a[j];
        }
        
        sort(a, a+N);
        
        if (K > (N/2)) {
            start = N - K;
            stop  = N;
        }
        else {
            start = 0;
            stop  = K;
        }
        for (int j = start; j < stop; j++)
            chk_sum += a[j];
        cout << (long)fabs(tot_sum - chk_sum - chk_sum) << endl;
    }
    
    return 0;
}
