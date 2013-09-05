
/*
 
 Where:			Codechef December Challenge 2012
 Link:			http://www.codechef.com/DEC12/problems/GRANAMA
 Type:			String Manipulation 
 Summary:		Question is to tell, whether after wrong process, the guess that he
				makes is consistent with the result after the actual process.
				Read Process.
 Other Notes:	Usage of unique(): moves all duplicates that are present adjacent
				to each other to the end, retaining only one copy of that element
				in the actual position.Eg:10 20 20 30 30 20 becomes 10 20 30 20 _ _
				and returns iterator to the element from where redundance starts,
				and thus the erase fn erases from this iterator returned, to end.
 */

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstdio>
using namespace std;
int main() {
    int T;
    string s1, s2;
    cin >> T;
    while(T--) {
        cin >> s1 >> s2;
        sort(s1.begin(),s1.end());
        sort(s2.begin(), s2.end());
        if (s1 == s2)
            cout << "YES" << endl;
        else {
            s1.erase(unique(s1.begin(), s1.end()), s1.end());
            s2.erase(unique(s2.begin(), s2.end()), s2.end());
            if (s1 == s2)
                cout << "NO" << endl;
            else
                cout << "YES" << endl;
        }
    }
    return 0;
}
