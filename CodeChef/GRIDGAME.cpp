
/*
 
 Where:			Codechef December Cook-Off, 23 December, 2012
 Link:			http://www.codechef.com/COOK29/problems/GRIDGAME
 Type:			Graph Theory...I think 
 Summary:		No Idea...
 Other Notes:	Nothing Yet....
 
 */

#pragma comment(linker,"/STACK:256000000")
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <complex>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <memory.h>
using namespace std;
#define sz(v) ((int)(v).size())
#define forn(i,n) for(int i=0;i<(n);++i)
#define forv(i,v) forn(i,sz(v))
#define pb push_back
#define mp make_pair
#define istr stringstream
#define fi first
#define se second
#define X first
#define Y second
#define clr(a,v) memset((a),(v),sizeof(a))
#define y0 asdy0
#define y1 asdy1
#define j0 asdj0
#define j1 asdj1
#define next asdnext
#define prev asdprev
#define link asdlink
#define unlink asdunlink
#define left asdleft
#define right asdright
#define hash asdhash
#define div asddiv
#define all(v) (v).begin(),(v).end()
typedef long long lng;
typedef unsigned int uint;
typedef unsigned long long ulng;
typedef unsigned char uchar;
typedef double ld;
typedef pair<int,int> PII;
typedef pair<ld,ld> PDD;
typedef pair<lng,lng> PLL;
typedef complex<double> com;
const ld PI=3.1415926535897932384626433832795;
const ld EPS=1e-12;
const int inf=1000000000;
const lng linf=1000000000000000000LL;
template<class T> inline T sqr(T x) { return x * x; }
int gcd(int a,int b){return a?gcd(b%a,a):b;}

set<PLL> st;
typedef set<PLL>::iterator iter;

void print(lng x){
	return;
	cout<<x<<": "<<endl;
	for(iter it=st.begin();it!=st.end();++it){
		cout<<it->X<<' '<<it->Y<<endl;
	}
	cout<<endl;
}

iter merge(iter it){
	while(true){
		iter it2=it;
		++it2;
		if(it2==st.end())
			return it;
		if(it2->X>it->Y)
			return it;
		lng b=it->X;
		lng e=it2->Y;
		st.erase(it);
		st.erase(it2);
		pair<iter,bool> p=st.insert(mp(b,e));
		it=p.X;
	}
}

vector<int> solve(vector<PII> pts,vector<PII> qs){
	int n=sz(pts);
	typedef map<lng,vector<lng> > themap;
	themap evs;
	map<PLL,vector<int> > qus;
	forn(i,n){
		evs[pts[i].X].pb(pts[i].Y);
	}
	int q=sz(qs);
	forn(i,q){
		qus[qs[i]].pb(i);
		if(!evs.count(qs[i].X))
			evs[qs[i].X]=vector<lng>();
	}
	vector<int> res(q,1);
	st.clear();
	lng px=0;
	for(themap::iterator it=evs.begin();it!=evs.end();++it){
		lng x=it->X;
		vector<lng> &ys=it->Y;
		ys.pb(linf*2);
		sort(all(ys));
		lng dt=x-px;
		print(x);
		while(dt>0){
			if(st.empty() || st.begin()->X != 0){
				st.insert(mp(0,0));
			}
			iter it1=st.begin();
			iter it2=it1;
			++it2;
			if(it2!=st.end() && it2->X-it1->Y<=dt){
				dt-=it2->X-it1->Y;
				lng b=it1->X;
				lng e=it2->Y;
				st.erase(it1);
				st.erase(it2);
				st.insert(mp(b,e));
			}else{
				lng b=it1->X;
				lng e=it1->Y+dt;
				st.erase(it1);
				st.insert(mp(b,e));
				dt=0;
			}
		}
		print(x);
		forv(i,ys){
			lng y=ys[i];
			iter it1=st.upper_bound(mp(y,linf*2));
			if(it1==st.begin())
				continue;
			--it1;
			if(it1->Y<=y)
				continue;
			lng b1=it1->X;
			lng e1=y;
			lng b2=y+1;
			lng e2=it1->Y;
			st.erase(it1);
			if(e1>b1)
				st.insert(mp(b1,e1));
			if(e2>b2)
				st.insert(mp(b2,e2));
		}
		print(x);
		lng py=0;
		forv(i,ys){
			lng y=ys[i];
			lng z=-1;
			if(y>py){
				iter it1=st.upper_bound(mp(py,linf*2));
				if(it1==st.begin()){
					z=py;
				}else{
					--it1;
					it1=merge(it1);
					if(it1->Y<y)
						z=max(it1->Y,py);
				}
				if(z!=-1){
					if(qus.count(mp(x,z))){
						vector<int> &vv=qus[mp(x,z)];
						forv(t,vv){
							res[vv[t]]=0;
						}
					}
					st.insert(mp(z,z+1));
				}
			}
			py=y+1;
		}
		px=x+1;
	}
	print(linf);
	return res;
}

vector<int> brute(vector<PII> pts,vector<PII> qs){
	int H=0,W=0;
	int n=sz(pts);
	int q=sz(qs);
	forn(i,n){
		H=max(H,pts[i].Y+1);
		W=max(W,pts[i].X+1);
	}
	forn(i,q){
		H=max(H,qs[i].Y+1);
		W=max(W,qs[i].X+1);
	}
	vector<vector<int> > wall(H,vector<int>(W,0));
	vector<vector<int> > win(H,vector<int>(W,0));
	forn(i,n){
		wall[pts[i].Y][pts[i].X]=1;
	}
	forn(y,H){
		forn(x,W){
			bool w=wall[y][x];
			for(int xx=x-1;xx>=0 && !wall[y][xx];--xx){
				if(!win[y][xx]){
					w=true;
					break;
				}
			}
			for(int yy=y-1;yy>=0 && !wall[yy][x];--yy){
				if(!win[yy][x]){
					w=true;
					break;
				}
			}
			win[y][x]=w;
		}
	}
	vector<int> res(q);
	forn(i,q){
		res[i]=win[qs[i].Y][qs[i].X];
	}
	return res;
}

void gen(vector<PII> &pts,vector<PII> &qs,int lim,int n,int q){
	pts.clear();
	qs.clear();
	forn(i,n){
		pts.pb(mp(0,0));
		pts[i].X=rand()%lim;
		pts[i].Y=rand()%lim;
	}
	forn(i,q){
		qs.pb(mp(0,0));
		qs[i].X=rand()%lim;
		qs[i].Y=rand()%lim;
	}
}

void stress(){
	for(int lim=1;lim<=10;++lim){
		for(int n=1;n<=10;++n){
			for(int q=1;q<=10;++q){
				vector<PII> pts,qs;
				gen(pts,qs,lim,n,q);
				vector<int> b=brute(pts,qs);
				vector<int> r=solve(pts,qs);
				if(b!=r){
					cout<<"failed "<<lim<<' '<<n<<' '<<q<<":"<<endl;
					forn(i,n){
						cout<<pts[i].X<<' '<<pts[i].Y<<endl;
					}
					cout<<endl;
					forn(i,q){
						cout<<qs[i].X<<' '<<qs[i].Y<<endl;
					}
					cout<<endl;
					forn(i,q){
						cout<<b[i]<<' ';
					}
					cout<<endl;
					forn(i,q){
						cout<<r[i]<<' ';
					}
					cout<<endl;
					return;
				}
			}
		}
	}
	cout<<"passed"<<endl;
}

int main() {
#ifdef __ASD__
	freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
	//stress();return 0;
	int tc;
	cin>>tc;
	forn(qqq,tc){
		int n;
		cin>>n;
		vector<PII> pts,qs;
		forn(i,n){
			int x,y;
			scanf("%d%d",&x,&y);
			pts.pb(mp(x,y));
		}
		int q;
		cin>>q;
		forn(i,q){
			int x,y;
			scanf("%d%d",&x,&y);
			qs.pb(mp(x,y));
		}
		vector<int> res=solve(pts,qs);
		forn(i,q){
			printf("%s\n",res[i]?"Alice":"Bob");
		}
	}
	return 0;
}
