#include <iostream>

using namespace std;

int tot = 100;

int fnCheckLeap(int yr) {
    int flag = 0;

    if ((yr % 4 == 0 && yr % 100 != 0) || yr % 400 == 0)
        flag = 1;

    return flag;
}

int main() {
    int daysOfYr[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int flag, count = 0, day = 7;

    for (int i = 1; i <= tot; i++) {
        daysOfYr[1] += fnCheckLeap(1900+i);
        cout << 1900+i << endl;
        for (int j = 0; j < 12; j++) {
            cout << j+1 << ":   ";
            while(day <= daysOfYr[j]) {
                if (day == 1)
                    count++;
                cout << day << "  ";
                day += 7;
            }
            day = day % daysOfYr[j];
            cout << day << endl << endl;
        }        
        daysOfYr[1] -= fnCheckLeap(1900+i);
    }
    cout << count << endl;

    return 0;
}                                                                                                                            
