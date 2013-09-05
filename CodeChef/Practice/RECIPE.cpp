#include <iostream>
using namespace std;
int GCD(int a, int b) {
    if (b == 0)
        return a;
    else
        return GCD(b,a%b);
}
int main() {
    int T, hcf, N, arr[100];

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        
        for (int j = 0; j < N; j++)
            cin >> arr[j];
        
        hcf = arr[0];
        
        for (int j = 1; j < N; j++)
            hcf = GCD(hcf, arr[j]);
        
        for (int j = 0; j < N; j++)
            cout << arr[j]/hcf << " ";
    }

    return 0;
}
