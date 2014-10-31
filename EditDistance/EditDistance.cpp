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


int EditDistance(string a, string b,int insertCost, int deletionCost, int subsCost){	
	/* Given two strings, a and b , we need to convert the first one into second */
	int n = a.size();
	int m = b.size();
	// if( insertCost == 0 ) return 0;   since insert cost and the delete cost is same, we'll always be able to convert first into second freely 
	// if( abs(n-m) > k ) return -1;/* if the diff. in the lenght is more than k, and a is >= 1 , it will always be more than k, so -1 */

	int dp[n+1][m+1];

	int i,j,k;
	
	dp[0][0] = 0;

	for(i=1;i<=n;i++) dp[i][0] = dp[i-1][0] + deletionCost;/* Since for j = 0 ,, the lenght of the second is 0, we need to delete all the i elelmtents of the first string */
	for(i=1;i<=m;i++) dp[0][i] = dp[0][i-1] + insertCost;

	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if( a[i-1] == b[j-1] ){
				dp[i][j] = dp[i-1][j-1];
			}else{
				dp[i][j] = min(dp[i-1][j-1] + subsCost , min( dp[i][j-1] + insertCost , dp[i-1][j] + deletionCost ) );
			} 
		}
	}



	return dp[n][m];
}

int main(){
	lld n,m,i,j,l,r,k,p,d,t;
	lld a,b;
	string str1, str2;
	// cout << EditDistance("S","SN",1,1,1);

	get(t);
	while(t--){
		cin >> str1;
		cin >> str2;
		get(a);
		get(b);
		get(k);
		cout << EditDistance(str1,str2,a,a,b) << "\n";


	}

	return 0; 	
 }














