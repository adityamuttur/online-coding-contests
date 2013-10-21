#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

#define SIZE 100005
#define MIN(M, N) ((M) < (N) ? (M) : (N))

int main() {

	int N, K, arr[SIZE], no_of_elements_to_sum;
	int unfairness, temp, least_unfairness, last;
	int segement_sums[SIZE];
	vector<int> v[SIZE];

	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr+N);

	segement_sums[0] = 0;
	for (int i = 0; i < K-1; i++)
		segement_sums[0] += arr[i];

	for (int i = 1; i < N-K+2; i++) {
		segement_sums[i] = segement_sums[i-1]-arr[i-1]+arr[K-2+i];
		// cout << segement_sums[i] << "  ";
	}
	// cout << endl;

	
	// cout << unfairness << endl << endl;
	unfairness = 0;
	for (int i = 0; i < K-1; i++)
		for (int j = i+1; j < K; j++)
			unfairness += (arr[j]-arr[i]);
	// cout << unfairness << endl;

	least_unfairness = unfairness;
	for (int i = 1; i < N-K+1; i++) {
		unfairness -= (segement_sums[i]-(arr[i-1]*(K-1)));
		unfairness += ((arr[i+K-1]*(K-1))-segement_sums[i]);
		least_unfairness = MIN(least_unfairness, unfairness);
	}

	printf("%d\n", least_unfairness);

	return 0;
}	



// no_of_elements_to_sum = K*(K-1)/2;
// 	unfairness = 0;
// 	for (int i = 0; i < K-1; i++) {
// 		temp = 0;
// 		for (int j = i+1; j < K; j++) {
// 			temp += (arr[j] - arr[i]);
// 			unfairness += (arr[j] - arr[i]);
// 		}
// 		v[i].push_back(temp);
// 	}

// 	// cout << unfairness << endl << endl;
// 	least_unfairness = unfairness;
// 	for (int i = 1; i < N-K; i++) {
// 		// cout << "i: " << i << endl;
// 		unfairness -= v[i-1].back();
// 		for (int j = i; j < i+K-1; j++) {
// 			// cout << "j: " << j << endl;
// 			temp = (arr[i+K-1]-arr[j]);
// 			if (v[j].size() == 0)
// 				last = 0;
// 			else
// 				last = v[j].back();
// 			v[j].push_back(last+temp);
// 			unfairness += temp;
// 		}
// 		// cout << unfairness << endl << endl;
// 		least_unfairness = MIN(least_unfairness, unfairness);
// 	}