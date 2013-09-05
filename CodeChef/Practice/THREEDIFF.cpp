#include<iostream>
#include<string>
#include<cstring>
#include<sstream>
#include<algorithm>
#include<stdint.h>
#define MOD 1000000007
#define MAX 10000
#define CTR 11
using namespace std;
uint64_t mod (string inp) {
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
string func;
void multiply (char a[], char b[]) {
    static char mul[MAX];
    char c[MAX];
    char temp[MAX];
    int la, lb;
    int i, j, k = 0, x = 0, y;
    long int r = 0;
    long sum = 0;

    la = strlen (a) - 1;
    lb = strlen (b) - 1;

    for (i = 0; i <= la; i++)
        a[i] = a[i] - 48;

    for (i = 0; i <= lb; i++)
	    b[i] = b[i] - 48;

    for (i = lb; i >= 0; i--) {
	    r = 0;
	    for (j = la; j >= 0; j--) {
	        temp[k++] = (b[i] * a[j] + r) % 10;
	        r = (b[i] * a[j] + r) / 10;
	    }
    	temp[k++] = r;
	    x++;
	    for (y = 0; y < x; y++)
	        temp[k++] = 0;
    }

    k = 0;
    r = 0;
    for (i = 0; i < la + lb + 2; i++) {
	    sum = 0;
	    y = 0;
	    for (j = 1; j <= lb + 1; j++) {
	        if (i <= la + j)
		        sum = sum + temp[y + i];
	        y += j + la + 1;
	    }
	    c[k++] = (sum + r) % 10;
	    r = (sum + r) / 10;
    }
    c[k] = r;
    j = 0;
    for (i = k - 1; i >= 0; i--)
	    mul[j++] = c[i] + 48;
    mul[j] = '\0';
    func.clear();
    func = mul;
}
int main() {
    string s1, s2, s3, ans1, ans2;
    uint64_t p[3], mod_ans;
    char str1[10000], str2[10000], str3[10000], str4[10000];
    stringstream s;
    int T;
    cin >> T;
    while (T--) {
        cin >> p[0] >> p[1] >> p[2];
        sort(p, p+3);
        p[1]--;
        p[2]-=2;
        
        if (p[0]*p[1]*p[2] == 0) {
            cout << 0 << endl;
            continue;
        }
        s.clear();
        s.str(string());
        s << p[0];
        s1 = s.str();

        s.clear();
        s.str(string());
        s << p[1];
        s2 = s.str();

        s.clear();
        s.str(string());
        s << p[2];
        s3 = s.str();
        //cout << p[0] << "   " << p[1] << "   " << p[2] << endl;
        strcpy(str1, s1.c_str());
        strcpy(str2, s2.c_str());
        multiply(str1, str2);
        
        ans1 = func;

        strcpy(str3, s3.c_str());
        strcpy(str4, ans1.c_str());
        multiply(str3, str4);
        ans2 = func;
        
        //cout << "ans : " << func << endl;
        
        mod_ans = mod(ans2);
        //cout << ans1 << "   " << ans2 << endl;
        ans1.clear();
        s1.clear();
        s2.clear();
        s3.clear();
        ans2.clear();
        cout << mod_ans << endl;
        mod_ans = 0;
    }
    return 0;
}
