#include "bits/stdc++.h"
using namespace std;



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
	vector< int > a(sieve(123).second);		
	vector< int > b = sieve(1000000).second;
	for (int i = 0; i < b.size() ; ++i)
	{
			cout << b[i] << endl;
	}	
	return 0;
}

