#include "bits/stdc++.h"
using namespace std;

long long lcm( vector< int > a ) { 
	int s = a.size();
	long long lcm  = a[0];
	for(int i=1;i<s;i++) lcm = (lcm * a[i])/__gcd(lcm,(long long)a[i]);
	return lcm;
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


pair < vector< int > , long long  >  factorise(long long int a , vector< int > primes  ){
	// vector< int > primes(sieve(100000).second);

	/*
		@arg a can be at max 10^12.
 		a list of all primes should be an input to the function 
 		Usage : 
 			vector< int > a = sieve(1000000).second;
			vector< int > g = factorise(1123,a);
			This function will return the factorization of a number less than 10^6. In case the number
			is prime and more than 10^6. The second number of the returned pair will denote that number. 	
		
	*/
	int ps = primes.size();
	vector< int > fs(ps);
 	int i,j,k,l,m,n;


	for(i=0; i<ps && a > 1 ;i++){
		int count = 0;
		while(a%primes[i] == 0) (count++,a /= primes[i]);
		fs[i] = count;

	}

	return make_pair( fs , a ) ;

}
long long  power(long long  a , long long  b,long long  MOD){
	long long ans = 1;
	while(b){ 
		if( b&1 ) ans = (ans * a);
		if(ans > MOD) ans %= MOD;
		a = (a * a);
		if(a > MOD) a %= MOD;
		
		b >>= 1;
	}
	return ans;
}

long long lcm( vector < int > a, long long  mod ){
	/*
		This function is only valid if the numbers are within 10^6.
	*/

	int size = a.size();
	vector< int > primes = sieve(1000000).second;
	int psize = primes.size();
	vector< int > temp;
	vector< int > fs(psize);
	
	for(int i=0;i<size;i++){
		temp = factorise(a[i],primes).first;
		for(int j=0;j<psize;j++){
			fs[j] = max(temp[j],fs[j]);
		}
	}

	long long lcm = 1;

	for(int i=0;i<psize;i++){
		lcm = lcm * power(primes[i],fs[i],mod);
		if(lcm > mod) lcm %= mod;
	}

	return lcm;
}	

int main(){
	vector< int > a;
	
	for(int i=0;i<10;i++){
		a.clear();
		a.push_back(rand()%1000);
		a.push_back(rand()%1000);
		a.push_back(rand()%1000);

		cout << lcm(a,1e18) << " " << lcm(a) << endl;
	}
	return 0;
}