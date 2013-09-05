
/*
 
 Where:			Codechef December Cook-Off, 23 December, 2012
 Link:			http://www.codechef.com/COOK29/problems/EXGCD
 Type:			Number Theory 
 Summary:		No Idea....
 Other Notes:	Nothing Yet....
 
 */

#include <stdio.h>
const int md=1000000007;
int t,n,mx,i,j,k,l[7],r[7];
long long res[200020],all,p;
long long pw(long long x, int y) {
	if (y==0) return 1LL;
	if (y&1) return (pw(x,y-1)*x)%md;
	long long z=pw(x,y/2);
	return (z*z)%md;
}
int main() {
	scanf("%d",&t);
	while (t--) {
		scanf("%d",&n);
		mx=all=1;
		for (i=0; i<n; i++) {
			scanf("%d%d",&l[i],&r[i]);
			if (r[i]>mx) mx=r[i];
			all=(all*(r[i]-l[i]+1))%md;
		}
		res[1]=all;
		for (i=mx; i>1; i--) {
			res[i]=1;
			for (j=0; j<n; j++) {
				res[i]=(res[i]*(r[j]/i-(l[j]-1)/i))%md;
				if (res[i]==0) break;
			}
			for (j=i+i; j<=mx; j+=i) {
				res[i]-=res[j];
				if (res[i]<0) res[i]+=md;
			}
			res[1]-=res[i];
			if (res[1]<0) res[1]+=md;
		}
		p=0;
		for (i=1; i<=mx; i++) p=(p+res[i]*i)%md;
		printf("%d\n",int((((md-p)%md)*pw(all,md-2))%md));
	}
	return 0;
}