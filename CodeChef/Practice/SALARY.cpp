#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
    int T, N, temp, min_op;
    vector <int> v;
    cin >> T;
    while (T--) {
        cin >> N;
        while (N--) {
            cin >> temp;
            v.push_back(temp);
        }
        sort(v.begin(), v.end());
        min_op = 0;
        for (vector<int>::iterator p = v.begin()+1; p != v.end(); p++)
            min_op = min_op + (*p) - v[0];
        cout << min_op << endl;
        v.clear();
    }
    return 0;
}
