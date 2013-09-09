#include <iostream>
#include <algorithm>

using namespace std;

int main () {
	int T, arr[8];
	char ch;

	cin >> T;
	cin.get();
	for (int i = 0; i < T; i++) {
		for (int j = 0; j < 8; j++)
			arr[j] = 0;
		while ((ch = cin.get()) != '\n') {
			switch (ch) {
				case 'H': arr[0]++;break;
				case 'A': arr[1]++;break;
				case 'C': arr[2]++;break;
				case 'K': arr[3]++;break;
				case 'E': arr[4]++;break;
				case 'R': arr[5]++;break;
				case 'U': arr[6]++;break;
				case 'P': arr[7]++;break;
				default:  break;
			}
		}
		arr[2] /= 2;
		sort(arr, arr+8);
		cout << "Case #" << i+1 << ": " << arr[0] << endl;
	}

	return 0;
}