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

/*  This implementation is point update and range query */


class BIT{
public:
	int n; /* Number of elements */
	vector< int > a;
	vector< int > tree;
	BIT(int _n){
		a.push_back(0);
		n = _n;
		tree.resize(n+1,0);
	}
	/* This method is 1 indexed */
	void update(int add,int idx){
		/*  Add the number "add" to the index idx */
		while(idx <= n){
			tree[idx] += add;
			idx += idx & -idx;
		}
	}
	void printtree(){
		show(tree);
	}

	int CumulativeTill(int idx){
		int sum = 0;
		while(idx > 0){
			sum += tree[idx];
			idx -= idx & -idx;	
		}
		return sum;
	}

	int at(int idx){
		return CumulativeTill(idx) - CumulativeTill(idx-1);
	}

	int rangeSum(int l, int r){
		return CumulativeTill(r) - CumulativeTill(l-1);
	}

};



class BIT2{
	/* Range Updates and point queries */
	/* This is usully used in questions where initially all elements are zero  */
public:
	vector<int> tree;
	int n; /* number of elements*/
	BIT2(int _n){	
		n = _n;
		tree.resize(n+1,0);
	}
	void update(int a, int idx){
		while(idx<=n){
			tree[idx] += a;
			idx += (idx & -idx);
			// cout << idx << endl;
		}
	}
	void rangeUpdate(int l, int r, int x){
		/* Add x from a to b */ 
		update(x,l);
		update(-1*x,r+1);
	}
	int at(int idx){
		int ans = 0;
		while(idx>0){
			ans += tree[idx];
			idx -= idx & -idx;
		}
		return ans;
	}
};


int main(){
	lld n,m,i,j,l,r,k,p,d,q;



	lld t;
	get(t);
	while(t--){

		get(n);
		get(m);
		BIT2 bit(n);
		while(m--){
			get(l);
			get(r);
			get(k);	
			l++;
			r++;

			bit.rangeUpdate(l,r,k);
		}
		get(q);
		while(q--){
			get(k);
			k++;
			printf("%d\n",bit.at(k));
		}

	}

	return 0; 	
 }














