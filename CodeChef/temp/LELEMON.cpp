// Little Elephant likes lemonade.

// When Little Elephant visits any room, he finds the bottle of the lemonade in that room that contains the 
// greatest number of litres of lemonade and drinks it all.

// There are n rooms (numbered from 0 to n-1), each contains Ci bottles. Each bottle has a volume (in litres). 
// The first room visited by Little Elephant was P0-th, the second - P1-th, ..., the m-th - Pm-1-th room. 
// Note that Little Elephant may visit a room more than once.

// Find for Little Elephant the total volume of lemonade he has drunk.
// Input

// First line of the input contains single integer T - the number of test cases. T test cases follow. 
// First line of each test case contains pair of integers n and m. Second line contains m integers separated 
// by a single space - array P. Next n lines describe bottles in each room in such format: Ci V0 V1 ... VCi-1, 
// where V is the list of volumes (in liters) of all bottles in i-th room.
// Output

 

// In T lines print T integers - the answers for the corresponding test cases.
// Constraints

 

// 1 <= T <= 10

// 1 <= n, Ci <= 100

// 1 <= m <= 10^4

// 0 <= Pi < n

// 1 <= Vi <= 10^5
// Example

// Input:
// 2

// 3 3
// 0 2 1

// 3 1 2 3
// 1 7
// 2 4 7

// 4 7
// 0 1 3 0 1 0 0
// 1 7
// 3 9 4 5
// 7 1 2 3 4 5 6 7
// 1 1

// Output:
// 17
// 22

#include <iostream>
#include <algorithm>

using namespace std;

int get_max_and_set_to_zero(int arr[], int len) {
	int max_index = 0, max_value;
	for (int i = 1; i < len; i++) {
		if (arr[max_index] < arr[i]) {
			max_index = i;
		}
	}
	max_value = arr[max_index];
	arr[max_index] = 0;
	return max_value;
}

int main() {
	unsigned long long T, N, M, C[101], drinks[101][101], P[101], current_room;
	unsigned long long ans;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> N >> M;
		for (int j = 0; j < M; j++) {
			cin >> P[j];
		}
		for (int j = 0; j < N; j++) {
			cin >> C[j];
			for (int k = 0; k < C[j]; k++) {
				cin >> drinks[j][k];
			}
		}
		ans = 0;
		for (int j = 0; j < M; j++) {
			current_room = P[j];
			ans += get_max_and_set_to_zero(drinks[current_room], C[current_room]);
			// cout <<` j << " " << ans << endl;
		}
		cout << ans << endl;
	}

	return 0;
}