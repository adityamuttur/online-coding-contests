#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <string>
#include <utility>

using namespace std;

#define SIZE 1000000
#define MIN(M, N) ((M) < (N) ? (M) : (N))
#define MAX(M, N) ((M) > (N) ? (M) : (N))

int main() {

    int  T, occurances[26], arr[26];
    char temp;
    string output_cipher, output;
    string cipher, text;

    scanf("%d", &T);
    scanf("%*c");
    for (int i = 0; i < T; i++) {

        output.clear();
        output_cipher.clear();
        memset(occurances, 0, 26*sizeof(int));

        getline(cin, cipher);
        getline(cin, text);

        for (int j = 0; j < text.length(); j++) {
            if(!isalpha(text[j]))
                continue;
            temp = tolower(text[j]);
            occurances[temp-'a']++;
        }

        memcpy(arr, occurances, 26*sizeof(int));
        sort(arr, arr+26, greater<int>());
        for (int j = 0; j < 26; j++) {
            for (int k = 26-1; k >= 0; k--) {
                if (occurances[k] < 0)
                    continue;
                if (arr[j] == occurances[k]) {
                    occurances[k] = -1;
                    output_cipher += ('a' + k);
                }
            }
        }
        reverse(output_cipher.begin(), output_cipher.end());
        string::iterator p;
        for (int j = 0; j < text.length(); j++) {
            if (!isalpha(text[j])) {
                output += text[j];
            }
            else {
                temp = tolower(text[j]);
                p = find(output_cipher.begin(), output_cipher.end(), temp);

                temp = cipher[p-output_cipher.begin()];
                if (isupper(text[j]))
                    temp = toupper(temp);
                output += temp;
            }
        }
        cout << output << endl;
    
    }
    
    return 0;
}
