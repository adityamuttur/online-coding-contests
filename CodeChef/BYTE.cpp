#include <iostream>
#include <vector>
#include <stdint.h>
#include <stdio.h>
#include <utility>

using namespace std;

vector < pair<int64_t, uint64_t> > v;

int64_t byte (uint64_t n) {
    for (vector < pair <int64_t, uint64_t > >::iterator i = v.begin(); i != v.end(); i++)
        if (i->first == n)
            return i->second;
    int64_t check = (n/2) + (n/3) + (n/4);
    
    if (check <= n) {
        v.push_back(make_pair(n, n));
        return n;
    }
    
    int64_t a, b, c;
    
    a = byte(n/2);
    b = byte(n/3);
    c = byte(n/4);
    
    v.push_back(make_pair(n, a+b+c));

    return a+b+c;
}


int main() {
    int64_t n;

    while (scanf("%lld", &n) != EOF)
        cout << byte(n) << endl;
    
    return 0;
}
