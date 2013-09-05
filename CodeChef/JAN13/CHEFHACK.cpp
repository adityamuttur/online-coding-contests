/*
    FAST IO only upto 32 bit INTEGERS ONLY!!!!
    class to store int in string and add them.....to be used in future greately....

    lessons learnt: #defines o be used very often
                    use dynamic pgming and store values in arrays to ensure no exrta fn calls as they are very slow
                    STL are very slow...to be used scarcely
                    classes dont slow down by much....member fns can be used judiciously
                    to get arrays of size > 10^6, get 2d arrays: arr[10][10^6]
                    how to expess the abive array as #define....ie, how to access element
                        #define ty(n, a, i) n[(int(a[i][0]/1000000))][(int)(a[i][0]%1000000)]
                    as far as possible, use int32_t or int64_t or uint32_t and so on....
                    Contains best prime generator....upto 10^7 in 0.16 secs
                    in main fn, we CAN do....ty(n,a,i)[2] in case of 3d array - like for can_push_val                
                    gdb: 
                        run - start pgm
                        run < input_file.txt
                        print var_name
                        g++ file.cpp -g to give line name in gdb
                        
*/

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <stdint.h>
#include <unistd.h>

#define limit 1000000
#define check_left(i, n) (i%n==0?1:0)
#define check_right(i, n) (i%n==n-1?1:0)
#define is_limit(i) (i>=0&&i<N*N?1:0)
#define ty(n, a, i) n[(int(a[i][0]/1000000))][(int)(a[i][0]%1000000)]

using namespace std;

uint32_t v[122501][2], no_primes, N;
uint32_t is_prime_check[11][1000001], can_push_val[11][1000001][2];

class string_int {
	char str[100];
	int end;
	public:
		string_int(){
			reset();
		}
		void reset() {
			end = 80;
			for (int i = 0; i <= 80; i++)
				str[i] = '0';
			str[81] = '\0';
		}
		string_int operator+(uint64_t a) {
			uint64_t temp, size = strlen(str+end), carry = 0;
			for (uint64_t i = 80; i != end-1; i--) {
				temp = str[i] - '0' + a%10 + carry;
				str[i] = temp%10+'0';
				if (temp > 9)
					carry = temp/10;
				else
					carry = 0;
				a /= 10;
			}
			if (carry != 0 || a != 0) {
				a += carry;
				while (a) {
					str[--end] = (a%10)+'0';
					a/=10;
				}
			}
			return (*this);
		}
		void display() {
			printf("%s\n", str+end);
		}
};


class FastInput
{
public:
FastInput ()
{
m_dataOffset = 0;
m_dataSize = 0;
m_v = 0x80000000;
}
int ReadNext ()
{
if (m_dataOffset == m_dataSize)
{
int r = read (0, m_buffer, sizeof (m_buffer));
if (r <= 0)
return m_v;
m_dataOffset = 0;
m_dataSize = 0;
int i = 0;
if (m_buffer[0] < '0')
{
if (m_v != 0x80000000)
{
m_data[m_dataSize++] = m_v;
m_v = 0x80000000;
}
for (; (i < r) && (m_buffer[i] < '0'); ++i);
}
for (; i < r;)
{
if (m_buffer[i] >= '0')
{
m_v = m_v * 10 + m_buffer[i] - 48;
++i;
}
else
{
m_data[m_dataSize++] = m_v;
m_v = 0x80000000;
for (i = i + 1; (i < r) && (m_buffer[i] < '0'); ++i);
}
}
}
return m_data[m_dataOffset++];
}
public:
uint8_t m_buffer[32768];
int m_data[16384];
size_t m_dataOffset, m_dataSize;
int m_v;
};

class FastOutput
{
public:
FastOutput ()
{
m_dataOffset = 0;
}
~FastOutput ()
{
}
void Flush ()
{
if (m_dataOffset)
{
if (write (1, m_data, m_dataOffset));
m_dataOffset = 0;
}
}
void PrintUint(int v, char d)
{
if (m_dataOffset + 11 > sizeof (m_data))
Flush ();
if (v < 100000)
{
if (v < 1000)
{
if (v < 10)
{
m_data[m_dataOffset + 0] = v + 48;
m_dataOffset += 1;
}
else if (v < 100)
{
m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48;
v /= 10;
m_data[m_dataOffset + 0] = v + 48;
m_dataOffset += 2;
}
else
{
m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48;
v /= 10;
m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48;
v /= 10;
m_data[m_dataOffset + 0] = v + 48;
m_dataOffset += 3;
}
}
else
{
if (v < 10000)
{
m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48;
v /= 10;
m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48;
v /= 10;
m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48;
v /= 10;
m_data[m_dataOffset + 0] = v + 48;
m_dataOffset += 4;
}
else
{
m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48;
v /= 10;
m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48;
v /= 10;
m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48;
v /= 10;
m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48;
v /= 10;
m_data[m_dataOffset + 0] = v + 48;
m_dataOffset += 5;
}
}
}
else
{
if (v < 100000000)
{
if (v < 1000000)
{
m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48;
v /= 10;
m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48;
v /= 10;
m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48;
v /= 10;
m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48;
v /= 10;
m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48;
v /= 10;
m_data[m_dataOffset + 0] = v + 48;
m_dataOffset += 6;
}
else if (v < 10000000)
{
m_data[m_dataOffset + 6] = v - v / 10 * 10 + 48;
v /= 10;
m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48;
v /= 10;
m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48;
v /= 10;
m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48;
v /= 10;
m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48;
v /= 10;
m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48;
v /= 10;
m_data[m_dataOffset + 0] = v + 48;
m_dataOffset += 7;
}
else
{
m_data[m_dataOffset + 7] = v - v / 10 * 10 + 48;
v /= 10;
m_data[m_dataOffset + 6] = v - v / 10 * 10 + 48;
v /= 10;
m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48;
v /= 10;
m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48;
v /= 10;
m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48;
v /= 10;
m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48;
v /= 10;
m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48;
v /= 10;
m_data[m_dataOffset + 0] = v + 48;
m_dataOffset += 8;
}
}
else
{
if (v < 1000000000)
{
m_data[m_dataOffset + 8] = v - v / 10 * 10 + 48;
v /= 10;
m_data[m_dataOffset + 7] = v - v / 10 * 10 + 48;
v /= 10;
m_data[m_dataOffset + 6] = v - v / 10 * 10 + 48;
v /= 10;
m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48;
v /= 10;
m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48;
v /= 10;
m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48;
v /= 10;
m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48;
v /= 10;
m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48;
v /= 10;
m_data[m_dataOffset + 0] = v + 48;
m_dataOffset += 9;
}
else
{
m_data[m_dataOffset + 9] = v - v / 10 * 10 + 48;
v /= 10;
m_data[m_dataOffset + 8] = v - v / 10 * 10 + 48;
v /= 10;
m_data[m_dataOffset + 7] = v - v / 10 * 10 + 48;
v /= 10;
m_data[m_dataOffset + 6] = v - v / 10 * 10 + 48;
v /= 10;
m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48;
v /= 10;
m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48;
v /= 10;
m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48;
v /= 10;
m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48;
v /= 10;
m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48;
v /= 10;
m_data[m_dataOffset + 0] = v + 48;
m_dataOffset += 10;
}
}
}
m_data[m_dataOffset++] = d;
}
void PrintChar (char d)
{
if (m_dataOffset + 1 > sizeof (m_data))
Flush ();
m_data[m_dataOffset++] = d;
}
void ReplaceChar (int offset, char d)
{
m_data[m_dataOffset + offset] = d;
}
public:
uint8_t m_data[32768];
size_t m_dataOffset;
};

void gen_prime() {
uint32_t upperBound = 10000000, upperBoundSquareRoot = (int) sqrt ((double) upperBound);
bool *isComposite = new bool[upperBound + 1];
no_primes = 0;
memset (isComposite, 0, sizeof (bool) * (upperBound + 1));
for (uint32_t m = 2; m <= upperBoundSquareRoot; m++) {
if (!isComposite[m]) {
is_prime_check[m/1000000][m%1000000] = ++no_primes;
for (uint32_t k = m * m; k <= upperBound; k += m)
isComposite[k] = true;
}
}
for (uint32_t m = upperBoundSquareRoot; m <= upperBound; m++)
if (!isComposite[m])
is_prime_check[m/1000000][m%1000000] = ++no_primes;
delete[]isComposite;
}

inline uint32_t can_push(long p, uint32_t type) {
if ( (p >= 0) && (p < N*N) ) {
if (ty(is_prime_check, v, p) == 0) {
if ((type == 0 && v[p][0]%2 == 0) || (type == 1 && v[p][0]%2 != 0))
return 1;
else
return 0;
}
}
return 0;
}

FastInput g_fi;
FastOutput g_fo;

int main() {
	uint32_t T, val, even_or_odd, start, stop, q[122501], pos = 0;
	string_int ans;

	T = g_fi.ReadNext();
	gen_prime();

	for (int yy = 0; yy < T; yy++) {
		N = g_fi.ReadNext();
		for (int i = 0; i < N*N; i++) {
			v[i][0] = g_fi.ReadNext();
			v[i][1] = 0;
			ty(can_push_val, v, i)[0] = can_push(i, 0);
			ty(can_push_val, v, i)[1] = can_push(i, 1);
		}
		ans.reset();
		for (int i = 0; i < N*N; i++) {
			if (!v[i][1]) {
				val = ty(is_prime_check, v, i);
				if (val != 0)
					ans = ans+((uint64_t)(val-1));
				else {
					start = stop = 0;
					q[stop++] = i;
					even_or_odd = v[i][0]%2;
					if (!even_or_odd)
						ans = ans+((uint64_t)(v[i][0]/2));
					else
						ans = ans+((uint64_t)(v[i][0]+3)/2);
					while(start<stop) {
						pos = q[start];
						start++;
						v[pos][1] = 1;
						if(is_limit(pos-1))
							if (!check_left(pos, N) && ty(can_push_val, v, pos-1)[even_or_odd])
								if (!v[pos-1][1]) {
									v[pos-1][1] = 1;
									q[stop++] = (pos-1);
								}
						if(is_limit(pos-N))
							if (ty(can_push_val, v, pos-N)[even_or_odd])
								if (!v[pos-N][1]) {
									v[pos-N][1] = 1;
									q[stop++] = (pos-N);
								}
						if(is_limit(pos+1))
							if (!check_right(pos, N) && ty(can_push_val, v, pos+1)[even_or_odd])
								if (!v[pos+1][1]) {
									v[pos+1][1] = 1;
									q[stop++] = (pos+1);
								}
						if(is_limit(pos+N))
							if (ty(can_push_val, v, pos+N)[even_or_odd])
								if (!v[pos+N][1]) {
									v[pos+N][1] = 1;
									q[stop++] = (pos+N);
								}
					}
				}
			}
		}
		ans.display();
	}
	return 0;
}