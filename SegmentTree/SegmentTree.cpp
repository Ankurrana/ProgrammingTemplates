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
#define show(a) tr(a,it){ cout << *it << " " ; } cout << endl;
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

vector< int > a; 

class N{
public:
	int minimum;	
	int maximum;
	int lazy;/*   This Variable holds the data which is required in lazy update */

	N():minimum(1e8),maximum(-1 * 1e8){ lazy = 0;};	
	N merge(const N &other){
		N result;
		result.minimum =  min( lazy + minimum, other.lazy +  other.minimum);
		result.maximum =  max( lazy + maximum, other.lazy + other.maximum);
		return result;
	}
};

N SegTree[1000000];

N buildTree(int index, int l, int r){
	int mid = (l+r)>>1;
	if( l == r ) {  SegTree[index].maximum = SegTree[index].minimum= a[l]; }
	else{
		SegTree[index] = buildTree(2*index+1,l,mid).merge(buildTree(2*index+2,mid+1,r));
	}
	return SegTree[index];
}


/* The updates are of type a, adding p to all elements in the range l to r */


N query(int index,int l,int r, int ql, int qr,int p){
	if( ql <= l && r <= qr )
		return SegTree[index]; 
	int mid = (l+r)>>1;
	N n1, n2;	
	if(ql<=mid) n1 = query(2*index+1,l,mid,ql,min(mid,qr));
	if(qr>mid)  n2 = query(2*index+2,mid+1,r,max(ql,mid+1),qr);
	return  n1.merge(n2);
}


void update(int index, int l , int r, int ql, int qr, int p){

}
int main(){
	lld n,m,i,j,l,r,k,p,d,q;
	vi::iterator it;

	get(n);
	fill(a,n);


	buildTree(0,0,n-1);



	get(q);
	while(q--){
		get(l);
		get(r);

		N temp = query(0,0,n-1,l,r);

		int mymin = temp.minimum;



		double mymax3 = (temp.maximum);

		int mymax1 = 0 , mymax2 = 0;
		if(l>0) 
			mymax1 = query(0,0,n-1,0,l-1).maximum;
		if(r < n-1)
			mymax2 = query(0,0,n-1,r+1,n-1).maximum;


		printf("%.1f\n", max(  mymin +  (mymax3 - mymin)/2 ,(double)mymin + (double)max(mymax1,mymax2)     )  );


	}

	return 0; 	
 }








/*I need to create a snple template */




