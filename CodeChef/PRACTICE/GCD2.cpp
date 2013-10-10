#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <stdint.h>

#define CTR 280

using namespace std;
string intToString(int i) {
    stringstream ss;
    string s;
    
    ss << i;
    s = ss.str();

    return s;
}

uint64_t mod (string inp, int MOD) {
    string s = inp, temp;
    stringstream s_stream;
    char str1[100], str2[100], str3[100];
    int split, next, len_str3;
    uint64_t ans;

    while(s.length() > CTR) {
        split = (CTR > s.length())?s.length():CTR;
        s.copy(str1, split, 0);
        next  = (s.length() - split > 0)?s.length()-split:0;
    
        s.copy(str2, next, split);
        str1[split] = '\0';
        str2[next]  = '\0';
        //cout << "copies post copy: " << str1 << "   " << str2 << endl;
        
        s_stream << str1;
        s_stream >> ans;
        
        ans = ans%MOD;
        
        s_stream.clear();
        s_stream.str(string());
        temp.clear();
        //cout << "ans: " << ans << endl;
        s_stream << ans;
        temp = s_stream.str();
        //cout << "temp: " << temp << endl;
        temp += str2; 
        //cout << "next ite: " << temp << endl << endl;
        s = temp;
        s_stream.clear();
        s_stream.str(string());
        temp.clear();
    }
    
    s_stream.clear();
    s_stream.str(string());

    len_str3 = s.length();
    s_stream << s.c_str();
    s_stream >> ans;
    
    return ans%MOD;
}

uint64_t gcd(uint64_t a, uint64_t b) {
    if (b == 0)
        return a;
    else {
        return gcd(b,mod(intToString(a),b));
    }
}

int main() {
    int T, temp, MOD;
    string i;

    cin >> T;
    for (int J = 0; J < T; J++) {
        cin >> MOD >> i;
        temp = mod(i, MOD);
        cout << gcd(MOD, temp) << endl;
    }
    return 0;
}
