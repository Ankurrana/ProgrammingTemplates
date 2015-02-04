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

vector< long long int > a; 

class N{
public:
	lld maximum;
	lld sum;
	
	lld interdata; 
	/*  
		This is used as an intermediate data used in the update function , currently no changes are made to the 
		actual array itself , this intermediate data somehow maintains the information of the chages made to a range denoted 
		by the Segtree node. This technique can be used in segment trees wherein the changes are relative to the 
		initial elements , But in case the element itself is changed then we need to make changes to the system.
	*/
	
	N(){ 
		sum = 0;
		maximum = -1*1e8;
	};	
	N merge(const N &other){
		N result;
		result.sum = sum + other.sum;
		result.maximum =  max( maximum,other.maximum);
		return result;
	}
};

N SegTree[2000000];

N buildTree(int index, int l, int r){
	int mid = (l+r)>>1;
	if( l == r ) {  
		SegTree[index].maximum = a[l]; 
		SegTree[index].sum = a[l];
	}
	else{
		SegTree[index] = buildTree(2*index+1,l,mid).merge(buildTree(2*index+2,mid+1,r));
	}
	return SegTree[index];
}


/* The updates are of type a, adding p to all elements in the range l to r */


N query(int index,int l,int r, int ql, int qr,lld ){
	if( ql <= l && r <= qr )
		return SegTree[index]; 
	int mid = (l+r)>>1;
	N n1, n2;	
	if(ql<=mid) n1 = query(2*index+1,l,mid,ql,min(mid,qr));
	if(qr>mid)  n2 = query(2*index+2,mid+1,r,max(ql,mid+1),qr);
	return  n1.merge(n2);
}

/*
  This implementation of update doesn't ever 
*/
void update(int index, int l , int r, int ql,int qr ,int p){

	int mid = (l+r)>>1;
	
	if(  l>=ql && qr<=r ){
			/* 
				make chages to the interdata element of the node
			*/
	}	

	if( l == r ){
		SegTree[index].maximum = p;
		SegTree[index].sum = p;
		SegTree[index].left = p;
		SegTree[index].right = p;
		SegTree[index].isdecreasing = true;
		SegTree[index].isincreasing = true;

		return ;
	}

	if( idx <= mid ) { 
		update(2*index+1,l,mid,idx,p);
		
	}else{ 
		update(2*index+2,mid+1,r,idx,p);
	}

	SegTree[index] = SegTree[2*index+1].merge( SegTree[2*index + 2] );
}

int main(){
	lld n,m,i,j,l,r,k,p,d,q;
	vi::iterator it;

	get(n);
	fill(a,n);
	buildTree(0,0,n-1);
	get(m);
	lld x,y;
	while(m--){
		get(x);
		get(y);
		x--;
		y--;
		cout << query(0,0,n-1,x,y).maximum << endl;	
	}

	return 0; 	
 }








/*I need to create a snple template */




