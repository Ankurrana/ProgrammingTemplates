#include "bits/stdc++.h"
using namespace std;

typedef long long int lld;

long long NChooseK(int n,int k){
	if(k > n) return 0;
	if(2*k > n) k = n-k;
	if(k==1) return n;
	long long result = n;
	for(int i=2;i<=k;i++){
		result *= (n-i+1);
		result /= i;
	}
	return result;
}


long long nPr(lld n, lld r, lld mod){
	lld ans = 1;
	for(lld i = n;i>n-r;i--) ans = (ans * i)%mod;
	return ans;
}
int main(){
	// cout << NChooseK(31,7) << endl;
	cout << nPr(5,2,1e12) << endl;
	return 0;
}