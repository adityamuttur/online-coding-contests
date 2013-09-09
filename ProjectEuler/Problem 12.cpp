#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long num = 28, count = 0;

    for (int i = 0; count < 500; i++){
        count = 0;
        cout << num << "   ";
        for (int j = 1; j <= num; j++) {
            if (num % j == 0) {
                cout << j << "   ";
                count++;
            }
        }
        cout << "And Total Is " << count << endl;
        num += (8+i);
    }
    cout << num << endl;

    return 0;
}
