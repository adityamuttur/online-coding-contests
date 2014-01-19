#include <iostream>
#include <string>
#include <cstring>
#define SIZE 1000

using namespace std;

class Number {

	char str[SIZE+1];

	public:
		Number() {
			reset();
		}

		void reset() {
			memset(str, 0, SIZE*sizeof(char));
			str[0] = '1';
		}

		void multi(int a) {
			int temp, carry=0, i=0;
			for (i = 0; i < strlen(str); i++) {
				temp = ((str[i]-'0')*a)+carry;
				if (temp > 9) 
					carry = (temp/10);
				else
					carry = 0;
				str[i] = (temp%10)+'0';
			}
			while (carry>0) {
				str[i] = (carry%10)+'0';
				carry/=10;
				i++;
			}
		}

		void display() {
			for (int i = strlen(str)-1; i >= 0; i--)
				cout << str[i];
		}
};

int main() {

	int T, a;
	Number N;

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> a;
		N.reset();
		for (int j = 2; j <= a; j++)
			N.multi(j);
		N.display();
		cout << endl;
	}

	return 0;
}
