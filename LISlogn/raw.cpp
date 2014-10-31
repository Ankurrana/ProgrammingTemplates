#include "bits/stdc++.h"
using namespace std;

typedef vector<int> vi;
typedef vector< int >::iterator vit;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef long long int lld;

template < typename T >
inline void geta(T *a){
 T n=0,s=1;
 char p=getchar_unlocked();
 if(p=='-') s=-1;
 while((p<'0'||p>'9')&&p!=(-1)&&p!='-') p=getchar_unlocked();
 if(p=='-') s=-1,p=getchar_unlocked();
 while(p>='0'&&p<='9') { n = (n<< 3) + (n<< 1) + (p - '0'); p=getchar_unlocked(); }
 *a = n*s;
}


vector< int > longestIncreasingSubsequence( vector< int > &a ){

 if( a.empty() ) return a;
 vector< int > lis;
 vector< int >f; 
 vector<int>::iterator it , tit;
 it = a.begin();
 lis.push_back(a[0]); it++;
 f.push_back(0);
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
 for(int (i)=0;(i)<(n);(i)++) geta(&a[i]);
}



int main(){
 lld n,m,i,j,l,r,k,p,d;
 vi lis;
 vi a,b;
 geta(&n);
 fill(a,n);
 b = longestIncreasingSubsequence(a);
 for(typeof((b).begin()) itera = b.begin();itera!= (b).end();itera++){ cout << *itera << " "; };
 return 0;
 }
