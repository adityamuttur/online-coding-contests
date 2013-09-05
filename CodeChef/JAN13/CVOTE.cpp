#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main() {
	vector<string> v, v2;
	vector<string>::iterator p, out, out1;
	map<string, int> m1, m3;
	map<string, string> m2;
	string temp1, temp2;
	int N, M, max = 0;

	cin >> N >> M;
	while (N--) {
		cin >> temp1 >> temp2;
		m2[temp1] = temp2;
		v.push_back(temp1);
		v2.push_back(temp2);
	}
	while (M--) {
		cin >> temp1;
		m1[temp1]++;
		m3[m2[temp1]]++;
	}
	sort(v.begin(), v.end());
	sort(v2.begin(), v2.end());
	for (p = v.begin(); p != v.end(); p++) {
		if (m1[(*p)] > max) {
			out = p;
			max = m1[(*p)];
		}
	}
	max = 0;
	for (p = v2.begin(); p != v2.end(); p++) {
		if (m3[(*p)] > max) {
			out1 = p;
			max = m3[(*p)];
		}
	}

	cout << *out1 << endl;
	cout << *out << endl;

	return 0;
}