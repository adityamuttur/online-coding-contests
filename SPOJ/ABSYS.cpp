#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main () {
	int T, a, b, val, ans;
	string str[5], temp;
	size_t pos;
	stringstream st;

	cin >> T;
	for (int i = 0; i < T; i++) {
		for (int j = 0; j < 5; j++) {
			cin>>str[j];
			pos = str[j].find("machula"); 
			if (int(pos) != -1)
				val = j;
		}
		switch (val) {
			case 0:
				a = atoi(str[2].c_str());
				b = atoi(str[4].c_str());
				//istringstream (str[4]) >> b;
				ans = b-a;
				st << ans;
				temp = st.str();
				str[0].replace(str[0].begin(),str[0].end(),temp);
				break;
			case 2:
				istringstream (str[0]) >> a;
				istringstream (str[4]) >> b;
				ans = b-a;
				st << ans;
				temp = st.str();
				str[2].replace(str[2].begin(),str[2].end(),temp);
				break;
			case 4:
				istringstream (str[0]) >> a;
				istringstream (str[2]) >> b;
				ans = a+b;
				st << ans;
				temp = st.str();
				str[4].replace(str[4].begin(),str[4].end(),temp);
				break;
		}
		st.str(string());
		for (int j = 0; j < 5; j++) {
			cout<<str[j];
			if (j != 4)
				cout << " ";
		}
		cout << endl;
	}
	return 0;
}