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

void fill(vector<lld> &a, int n){
	a.resize(n);
	rep(n,i) get(a[i]);
}

class BIT{
public:
	vector<lld> tree;
	lld size;
	BIT(int n){tree.resize(n+1,0);size = n;}
	BIT( vector< lld > a ){
		tree.resize(a.size());
		size = a.size();
		for(int i=0;i<a.size();i++){ 
			update(i,a[i]); 
		} 
	}
	void update(int index, lld val){
		while(index<size){
			tree[index] += val;
			index |= (index+1);
		}
	}
	lld read(int index){
		lld sum  = 0;
		while(index >= 0){
			sum += tree[index];
			index = (index & (index+1))-1;
		}
		return sum;
	}

};

int main(){
	lld n,m,i,j,l,r,k,p,d,q;

	get(n);
	get(m);
	get(d);

	lld tree[1000010] = {0};
	while(m--){
		char c;
		scanf("%c",&c);
		if(c == 'Q'){
			get(p);
			lld ans = 0;
			while(idx > 0){ ans += tree[idx] ; idx -= (idx & -idx);}
			printf("%lld\n",ans+d);
		}else{
			get(p);
			get(q);
			get(k);
			q++
			while(p<=n){ tree[p] += k; p |= (p+1); }
			while(q<=n){ tree[q] +=-k; q |= (q+1); }
		}
	}

	return 0; 	
 }














