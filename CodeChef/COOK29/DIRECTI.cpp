#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>

using namespace std;

int main() {
	int T, r;
	string temp;
	string a;
	vector < pair<string, string> > v;
	pair <string, string> t;

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> r;
		while (temp != "on")
			cin >> temp;
		getline(cin, a);
		for (int j = 2; j <= r; j++) {
			cin >> temp;
			if (temp == "Left")
				temp = "Right on";
			else
				temp = "Left on";
			t.first = a;
			t.second = temp;

			v.push_back(t);
			cin >> temp;
			getline(cin, a);
		}
		t.first = a;
		t.second = "Begin on";
		v.push_back(t);
		for (int j = 1; j <= r; j++) {
			while (!v.empty()) {
				t = v.back();
				v.pop_back();
				cout << t.second << t.first << endl;
			}
		}
		if (i+1 != T)
			cout << endl;
		temp.clear();
	}
	return 0;
}