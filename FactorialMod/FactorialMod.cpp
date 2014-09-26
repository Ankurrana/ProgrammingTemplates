#include "bits/stdc++.h"
using namespace std;

long long power(long long  a , long long  b,long long  MOD){
	/*  Define MOD as a PreProcessor or remove from this function if it aint required  */
	long long ans = 1;
	while(b){ 
		if( b&1 ) 
			ans = (ans * a);
		if(ans > MOD)  ans %= MOD;
		a = (a * a);
		if(a > MOD)  a %= MOD;
		b >>= 1;				
	}
	return ans;
}

long long  modInverseFermat(long long  a , long long  m){
	return power(a,m-2,m);
}


long long factorialMod(int k, long long mod){
	/*
	*	Finds (K!)%mod using modular
	*	Only useful when m is really high 10^9 and the difference between mod 
	*  	ans k is relativelly small less than 10^3
	*
	* 	It uses Wilsons Algorithm which says (n-1)! = n-1 in modular prime number system
	*/

	if(k >= mod) return 0;
	long long ans = mod - 1;
	long long t = 1;
	for(long long q = k+1;q<mod;q++) t = (t * q)%mod;

	ans *= modInverseFermat(t,mod);
	if(ans > mod) ans %= mod;
	return ans;
}



// 	Testing 


long long BF(long long k, long long mod){
	long long res = 1;
	for(long long i=1;i<=k;i++) res = (res*i)%mod;
	return res;

}

int main(){
	cout << BF(91,97) << " " <<factorialMod(91,97) << endl;
	return 0;	
}