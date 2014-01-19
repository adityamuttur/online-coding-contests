#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {

    int T, counter, flag;
    string S;

    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> S;
        counter = 0;
        flag = 0;
        while (counter < S.length()) {
            if (S[counter] == '0') {
                if (S[counter+1] == '1') {
                    if (S[counter+2] == '0') {
                        flag = 1;
                        break;
                    }
                    else
                        counter+=2;
                }
                else
                    counter++;
            }
            else {
                if (S[counter+1] == '0') {
                    if (S[counter+2] == '1') {
                        flag = 1;
                        break;
                    }
                    else
                        counter+=2;
                }
                else
                    counter++;
            }
        }
        if (flag == 1)
            cout << "Good" << endl;
        else
            cout << "Bad" << endl;
    }

    return 0;
}
