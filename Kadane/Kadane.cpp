#include "bits/stdc++.h"
using namespace std;

typedef vector<long long int> vi;
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

/* 
   Kadane Algorithm is used to find maximum contiguous array sum and is very easy 
   Below implementation assumes that user is free to take any number of contiguous array elements, even none! 
	In case the user must choose atleast one, then instatiate maximum and curr_max to -inf.
*/

lld Kadane(vector<lld> &a){
	int n = a.size();
	lld maximum = 0;
	lld curr_max = 0;
	for(int i=0;i<n;i++){	
		curr_max = max(a[i],curr_max+a[i]);
		maximum = max(maximum, curr_max);
	}
	return maximum;
}	




int main(){
	lld n,m,i,j,l,r,k,p,d;
	vi a;
	fill(a,8);

	cout << Kadane(a);
		
	return 0; 	
 }














