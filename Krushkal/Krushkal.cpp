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

class DisjointSet{ /* Uses Path compression  */
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
	bool isSameSet(int u, int v){
		 if( parent(u) == parent(v) ) return true;
		 return false;
	}
	void join(int u, int v){
		nodes[parent(u)].count += nodes[parent(v)].count;
		nodes[parent(v)].parent = parent(u);
		nodes[v].parent =  parent(u);
	}
	int NumberMembers(int k){ return nodes[parent(k)].count; } /* returns the number of elements in its list */

	void desc(){
		int i = 0;
		for(i=0;i<count;i++){
			cout << "Node Number :  "  << i << " Parent : " << parent(i) << " parentCount  : " << nodes[parent(i)].count << endl; 
		}
	}

};


class Edge{
public:
	int u,v,w;
	Edge(int _u,int _v,int _w):u(_u),v(_v),w(_w){};
	bool operator<(const Edge & a) const{
		return w < a.w;
	}
};

vector< Edge > krushkal(vector< Edge > & edges, int n){ /* n  is the number of nodes */
	vector< Edge > final;
	sort(edges.begin(), edges.end());
	DisjointSet set;
	for(int i=0;i<=n;i++) set.add(1); /* Works with both 0 index and 1 index */
	vector< Edge >::iterator it;
	
	for(it=edges.begin(); it!=edges.end();it++){
		if( set.parent(it->u) != set.parent(it->v) ){
			set.join(it->u, it->v);
			final.push_back(*it);
			if(final.size() == (n-1) ) break;
		}
	}
	return final;
}

int main(){
	vector<Edge> edges; 
	edges.push_back(Edge(7,6,1));
	edges.push_back(Edge(8,2,2));
	edges.push_back(Edge(6,5,2));
	edges.push_back(Edge(0,1,4));
	edges.push_back(Edge(2,5,4));
	edges.push_back(Edge(8,6,6));
	edges.push_back(Edge(2,3,7));
	edges.push_back(Edge(7,8,7));
	edges.push_back(Edge(0,7,8));
	edges.push_back(Edge(1,2,8));
	edges.push_back(Edge(3,4,9));
	edges.push_back(Edge(5,4,10));
	edges.push_back(Edge(1,7,11));
	edges.push_back(Edge(3,5,14));

	vector<Edge> edges2 = krushkal(edges,9); 

	tr(edges2,it) cout << it->u <<" " << it->v << " " << it->w << endl;


	return 0; 	
 }














