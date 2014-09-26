#include "bits/stdc++.h"
using namespace std;

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

int main(){
	cout << NChooseK(31,7) << endl;
	return 0;
}