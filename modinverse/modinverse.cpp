#include "bits/stdc++.h"
using namespace std;

/* This function return the gcd of a and b followed by
    the pair x and y of equation ax + by = gcd(a,b)*/
pair<int, pair<int, int> > extendedEuclid(int a, int b) {
    int x = 1, y = 0;
    int xLast = 0, yLast = 1;
    int q, r, m, n;
    while(a != 0) {
        q = b / a;
        r = b % a;
        m = xLast - q * x;
        n = yLast - q * y;
        xLast = x, yLast = y;
        x = m, y = n;
        b = a, a = r;
    }
    return make_pair(b, make_pair(xLast, yLast));
}
 
int modInverse(int a, int m) {
    return (extendedEuclid(a,m).second.first + m) % m;
} 







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


int main(){

	cout << modInverseFermat(90,11);

	return 0;
}