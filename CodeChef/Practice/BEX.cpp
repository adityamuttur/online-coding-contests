#include<iostream>
#include<cstdio>
#include<string>
#include<stack>
#include<algorithm>
#include<vector>
#include<utility>
using namespace std;

int main() {
    int T, ctr;
    stack < pair <int, string> > s; 
    pair <int, string> temp; 
    vector<int> p;
    
    cin >> T;
    while (T--) {
        cin >> temp.first;
        if (temp.first != -1){
            cin >> temp.second;
            p.push_back(temp.first);
            s.push(temp);
        }
        else {
            sort(p.begin(), p.end());
            ctr = 0;
            while(s.top().first != p[0]) {
                s.pop();
                ctr++;
            }
            p.erase(p.begin());
            cout << ctr << " " << s.top().second << endl;
            s.pop();
        }
    }
    return 0;
}
