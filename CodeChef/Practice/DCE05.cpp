#include <iostream>
#include <cmath>
#include <string>
#include <cstring>

#define fr(a, b) for(int i = a; i < b; i++)
#define BS 64*1024

using namespace std;

char ibuffer[BS];
int ibuffer_offset=0;
int ibuffer_size=0;

static int inline fastread() {
	int r = 0, s = 1;

	while(1) {
		if(ibuffer_offset >= ibuffer_size) {
			ibuffer_size = read(0, ibuffer, BS);
			ibuffer_offset = 0;
		}
		if(ibuffer[ibuffer_offset] < 48) {
			if(s)
				ibuffer_offset++;
			else
				return r;
		}
		else {
			s = 0;
			r = r * 10 + ibuffer[ibuffer_offset++]-48;
		}
	}
}

static void inline fastprint(int v) {
	char str[13];
	int a = log10(v)+1;

	sprintf(str, "%d", v);
	str[a] = '\n';
	str[a+1] = '\0';
	a++;
	memcpy(str, str, a);
	write(1, str, a);
}

int main() {
	int t, a;

	t = fastread();
	fr(0, t) {
		a = fastread();
		a = (int)pow(2,(int)(log10(a) / log10(2)));
		fastprint(a);
	}

	return 0;
}