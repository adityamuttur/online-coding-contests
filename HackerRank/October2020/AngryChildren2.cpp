// https://www.hackerrank.com/contests/oct13/challenges/angry-children-2

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

#define SIZE 100005
#define MIN(M, N) ((M) < (N) ? (M) : (N))

int main() {

	unsigned long long N, K, arr[SIZE];
	unsigned long long segement_sums[SIZE];
	unsigned long long unfairness, least_unfairness, sum;

	scanf("%lld %lld", &N, &K);
	for (int i = 0; i < N; i++)
		scanf("%lld", &arr[i]);
	sort(arr, arr+N);

	// Sum of 1st set of K elements
	segement_sums[0] = 0;
	for (int i = 0; i < K-1; i++)
		segement_sums[0] += arr[i];

	// Sum of sets of elements of size K-1
	// i from 0->(N-(K-1)+1)
	// Since 1st is already computed
	// i=> 0->(N-K+2)
	for (int i = 1; i < N-K+2; i++)
		segement_sums[i] = segement_sums[i-1]-arr[i-1]+arr[K-2+i];

	unfairness = 0;
	sum = 0;
	for (int i = 0; i < K-1; i++) {
		// find the sum of the 1st i+1 elements
		// Then subtract this sum with i+2th element
		// multiplied by (i+1). This finds the sum
		// of the difference of the i+2th element with
		// each of the i+1 elements => arr[i+1]*(i+1)-sum
		sum += arr[i];
		unfairness += (arr[i+1]*(i+1)-sum);
	}

	least_unfairness = unfairness;
	for (int i = 1; i < N-K+1; i++) {
		// this line is to subtract the component of the unfairness
		// that involves the smallest element of the set of K
		// elements taken. So, use the segment sum of the K-1 
		// elements after it. Subtract the smallest_element*(K-1)
		// from the segment sum considered. Subtract this answer
		// acquired from the total unfairness to get remove the
		// component of the 1st element
		unfairness -= (segement_sums[i]-(arr[i-1]*(K-1)));

		// this line is to add the component of the unfairness
		// that involves the new element coming into the set.
		// Subtract this segment_sum of the K-1 elements present
		// (which is greater than or equal to the elements before it)
		// from the new_element*(K-1). Add this answer
		// acquired to the total unfairness to get add the
		// component of the new element
		unfairness += ((arr[i+K-1]*(K-1))-segement_sums[i]);

		// Get least value
		least_unfairness = MIN(least_unfairness, unfairness);
	}

	printf("%lld\n", least_unfairness);

	return 0;
}