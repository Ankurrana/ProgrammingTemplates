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

class node{
public:
	int data;
	int parent;
	int count;/* gives the number of nodes in its group, only if is one of the representative nodes. */
	node(int d, int p){
		data = d;
		parent = p;
		count = 1;
	}
};

class DisjointSet{
public:
	vector< node > nodes;  /* 0 indexed Everything */
	int count;
	DisjointSet(){ count = 0;}
	void add(int data){
		nodes.push_back(node(data,count)); /* Initially Everyone their own parent */
		count++;
	};
	int parent(int k){
		if( nodes[k].parent == k ) return k;
		else return nodes[k].parent = parent(nodes[k].parent) ;
	}
	int isSameSet(int u, int v){
		 if( parent(u) == parent(v) ) return true;
		 return false;
	}
	void join(int u, int v){
		nodes[parent(u)].count += nodes[parent(v)].count;
		nodes[parent(v)].parent = parent(u);
		nodes[v].parent =  parent(u);
	}
	int count(int k){ return nodes[parent(k)].count; } /* returns the number of elements in its list */

	void desc(){
		int i = 0;
		for(i=0;i<count;i++){
			cout << "Node Number :  "  << i << " Parent : " << parent(i) << " parentCount  : " << nodes[parent(i)].count << endl; 
		}
	}

};



int main(){
	DisjointSet set;
	set.add(2);
	set.add(2);
	set.add(2);
	set.add(2);
	set.add(2);
	set.add(2);

	set.join(1,2);
	set.join(2,3);
	set.join(3,4);

	// cout << set.isSameSet(2,4) << endl;
	set.desc();

	return 0; 	
}














