#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

#define SIZE 1000

unsigned long long get_solution(int L, int R) {
    unsigned long long l_no, r_no, l_no_min, r_no_min;
    unsigned long long ans, low, high;

    l_no = ((unsigned long long)log10(L))+1;
    r_no = ((unsigned long long)log10(R))+1;
    ans = 0;

    if (l_no == r_no) {
        // cout << ":p" << l_no << ":p" << r_no << endl;;
        // cout << ":p" << L << ":p" << R << endl;;
        ans = ( l_no*(R-L+1)*(R+L)/2 );
        ans = ans % 1000000007;
    }
    else if (r_no - l_no == 1) {
        low = L;
        high = (unsigned long long)(pow(10, l_no))-1;
        ans = ( l_no*( (high-low+1)*(low+high)/2 ) );
        ans = ans % 1000000007;

        low = (unsigned long long)(pow(10, l_no));
        high = R;
        ans += ( r_no*( (high-low+1)*(low+high)/2 ) );
        ans = ans % 1000000007;
    }
    else {
        low = L;
        high = (unsigned long long)(pow(10, l_no))-1;
        ans = ( l_no*( (high-low+1)*(low+high)/2 ) );
        // cout << ans << endl;
 
        for (unsigned long long i = l_no; i < r_no-1; i++) {
            low = (unsigned long long)(pow(10, i));
            high = (unsigned long long)(pow(10, i+1))-1;
            // cout << i << "  " << high << " " << low << endl;
            ans += ( (i+1)*( (high-low+1)*(low+high)/2 ) );
            ans = ans % 1000000007;

            // cout << ans << endl;
        }
 
        low = (unsigned long long)(pow(10, r_no - 1));
        high = R;
        ans += ( r_no*( (high-low+1)*(low+high)/2 ) );
        ans = ans % 1000000007;
        // cout << ans << endl;
    }

    return ans;
}

int main() {
    int T, L, R;

    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%d %d", &L, &R);
        cout << get_solution(L, R) << endl;
    }

    return 0;
    //45 + 9810 + 1483650 + 30010000
}