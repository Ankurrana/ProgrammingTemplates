#include "bits/stdc++.h"
using namespace std;

typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii;
typedef long long int lld;
#define getw getchar_unlocked
#define get(a) geta(&a)
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,it) for(typeof((c).begin()) it = c.begin();it!= (c).end();it++)
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define show(a) tr(a,it){ cout << *it << " "  << endl; }
#define rep(n,i) for(i=0;i<n;i++)


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

/*
	There can be two types of factorisation , one with primes and the other without finding primes and simply 
	using 0's in place of non primes.
*/





vector< int > prime_factorise( int a , vector< int > primes ){
	/*
		@a : the number to be factorised
		primes : the list of primes, basically upto a
		it will return a list of frequency where the first element of the 
		primes list is mapped to the first element of the return vector.

		External Dependency : 
				Sieve function to generate primes 

	*/

	vector< int >::iterator it;
	vector< int > result;

	for(it = primes.begin();it!=primes.end() && a>1 && (*it) * (*it) <= a ; it++  ){
		int count = 0;
		while( a%(*it) == 0 ) (count++, a /= *it);
		result.push_back(count);
	}
	if(a > 1){
		int index = lower_bound(primes.begin(),primes.end(),a) - primes.begin();
		result.resize(index+1);
		result[index] = 1;
	}

	return result;
}

pair< bitset< 1000001 > , vector< int > > sieve(int n){ 
	int i,j,k,l;
	bitset< 1000001 > isPrime;
	isPrime.set();
	vector< int > primes;
	isPrime[1] = 0;

	for(i=2;i*i<=n;i++){
		if(isPrime[i]) for(j=i*i;j<=n;j = j + i) isPrime[j] = 0;
	}
	for(i=1;i<=n;i++) if(isPrime[i]) primes.push_back(i);

	return make_pair( isPrime,primes );
}

int main(){
	lld i,j,k,l;
	vi primes = sieve(1000001).second;

	//The number you want to factorize

	int a = 51293341;

	vi fre = prime_factorise(a,primes);
	vi::iterator it2;
	for(vi::iterator it = fre.begin() , it2 = primes.begin(); it!= fre.end();it++ ,it2++ ){
		if(*it) cout << *it2 << "  " << *it << endl;
	}



	return 0; 	
 }




