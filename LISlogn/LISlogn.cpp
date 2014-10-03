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
#define show(a) tr(a,itera){ cout << *itera << " "; }
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
// 0 8 4 12 2 10 6 14 1 9 5 13 3 11 7 15
/* Nlogn Solution to LIS problem */
vector< int > longestIncreasingSubsequence( vector< int > &a ){
	
	/* Longest Strictly increasing subsequence */

	if( a.empty() ) return a;
	vector< int > lis;
	vector< int >f; /*It just maintains the possible index of the ith element in the final LIS*/ 
	vector<int>::iterator it , tit;
	it = a.begin();
	lis.push_back(a[0]); it++;
	f.push_back(0); /*  0th element can always hold 0th position in the final lis */
	int l = 1;

	for(;it!=a.end();it++){
		if( *it > *lis.rbegin()) {
			lis.push_back(*it);
			f.push_back(l++);
		}else{ 
			tit = lower_bound(lis.begin(),lis.end(),*it);
			*tit = *it;
			f.push_back(tit - lis.begin());
		}

	}


	vector< int > finallis;
	l--;
	for(int i=a.size()-1;i>=0;i--){
		if(f[i] == l) (finallis.push_back(a[i]),l--);
	}	
	reverse( finallis.begin(),finallis.end());
	
	return finallis;
 
}


void fill(vector<int> &a, int n){
	a.resize(n);
	rep(n,i) get(a[i]);
}



int main(){
	lld n,m,i,j,l,r,k,p,d;
	vi lis;
	vi a,b;
	get(n);
	fill(a,n);
	b = longestIncreasingSubsequence(a);
	show(b);
	return 0; 	
 }

// 0, 22, 9, 33, 21, 50, 41, 60












