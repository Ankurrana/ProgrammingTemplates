#include "bits/stdc++.h"
using namespace std;

long long lcm( vector< int > a ) { 
	int s = a.size();
	long long lcm  = a[0];
	for(int i=1;i<s;i++) lcm = (lcm * a[i])/__gcd(lcm,(long long)a[i]);
	return lcm;
}
	}


int main(){
	vector< int > a;
	a.push_back(2);
	a.push_back(4);
	a.push_back(34);
	a.push_back(234);
	cout << lcm(a);


	
	return 0;
}