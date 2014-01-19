#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {

    int T, L, D, S, C;
    double cur_d;

    cin >> T;
    for (int i = 0; i < T; i++) {   
        cin >> L >> D >> S >> C;

        cur_d = S * pow((C+1), D-1);

        if (cur_d >= ((double)L))
            cout << "ALIVE AND KICKING" << endl;
        else
            cout << "DEAD AND ROTTING" << endl;
    }

    return 0;
}
