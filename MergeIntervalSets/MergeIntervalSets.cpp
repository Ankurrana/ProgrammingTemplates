#include "bits/stdc++.h"
using namespace std;

typedef vector<int> vi;
typedef vector< int >::iterator vit;
typedef vector<vi> vvi; 
typedef pair<int,int> ii;
typedef long long int lld;

#define iterate(n) for(int qwe=0;qwe<n;i++)
#define getw getchar_unlocked
#define get(a) geta(&a)
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,it) for(typeof((c).begin()) it = c.begin();it!= (c).end();it++)
#define show(a) tr(a,it){ cout << *it << endl; }
#define rep(n,i) for(int (i)=0;(i)<(n);(i)++)


template < typename T >
inline void geta(T *a){
	T n=0,s=1;
	char p=getw();
	if(p=='-') s=-1;
	while((p<'0'||p>'9')&&p!=EOF&&p!='-') p=getw();
	if(p=='-') s=-1,p=getw();
	while(p>='0'&&p<='9') { n = (n<< 3) + (n<< 1) + (p - '0'); p=getw(); }
	*a = n*s;
}

void fill(vector<int> &a, int n){
	a.resize(n);
	rep(n,i) get(a[i]);
}

class Interval{
public:
	int s,e;
	Interval(int _a = 0,int _b = 0):s(_a),e(_b){};
	bool operator<(const Interval &other ) const{
		 return s < other.s;
	}
};

vector< Interval > merge(vector< Interval > &a){
	vector< Interval > res;
	for(int i=0;i< a.size();){
		int s = a[i].s;
		int e = a[i].e;
		while(i < a.size() && a[i].s <= e) { 
			e = max(e,a[i].e);
			i++; 
		};
		res.pb(Interval(s,e));
	}
	return res;
}


int main(){
	lld n,m,i,j,l,r,k,p,d;
	vector< Interval > a , b;
	// Interval a1(4,3),a2(3,4);
	get(n);
	rep(n,i){
		get(l); get(r);
		a.pb(Interval(l,r));
	}

	sort(a.begin(),a.end());

	b = merge(a);

	tr(b,it){
		cout << it->s << " " << it->e << endl;
	}
	


	return 0; 	
 }














