
/*
 
	Where:			Codechef December Cook-Off, 23 December, 2012
	Link:			http://www.codechef.com/COOK29/problems/TREEROOT
	Type:			Graph Theory
	Summary:		Column 1 is value of all nodes. Its sum is value of sum of all nodes.
					Column 2 is sum of "only children" of each Nodes. Its sum is sum of all nodes except the root.
					Their difference is the answer.
	Other Notes:	Nothing....

*/

#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <map>
#include <stack>
#include <algorithm>

using namespace std;

int main(){
	int T,N;

	cin >> T;
	while(T--) {
		int a, b;
		int sum1 = 0, sum2 = 0;

		cin >> N;
		for(int i = 0; i < N; i++) {
			cin >> a >> b;
			sum1 += a;
			sum2 += b;
		}
		cout << sum1-sum2 <<endl;
	}

	return 0;
}