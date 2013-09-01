#include <iostream>
#include <cstdlib>
#include <cstring>

#define MAX(M, N) (M>N?M:N)

using namespace std;

int main() {
    int T, N, start, end, count, max_count, a[2][1001];
    bool arr[200][1001];
    
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> N;
        for (int j = 0; j < N; j++)
            memset(arr[j], 0, 1001);
        
        for (int j = 0; j < N; j++)
            cin >> a[0][j];

        for (int j = 0; j < N; j++)
            cin >> a[1][j];
        
        for (int j = 0; j < N; j++) {
            start = a[0][j];
            end   = a[1][j];
           // cout << "start: " << start << " end: " << end << endl;
            memset(arr[j]+start, 1, end-start);
            /*
            for (int k = 1; k <= 10; k++)
                cout << arr[j][k] << "  ";
            cout << endl << endl;
            */
        }
        max_count = 0;
        for (int j = 1; j <= 1000; j++) {
            count = 0;
            for (int k = 0; k < N; k++)
                if (arr[k][j])
                    count++;
            max_count = MAX(count, max_count);
        }
        cout << max_count << endl;
    }
    
    return 0;
}
