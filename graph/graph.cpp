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
	int data; /* This data can be anything , just add variables in this class */
	vector< pair< int , int > > AL; /* Ajjacency list , (adjacent node, weight )  */ 
	
};

class Graph{
public:
	int N; /* total number of nodes in the graph*/
	vector< node > nodes;
	Graph(int n){ N = n;nodes.resize(n+1);} /* 1 indexed */
	void add(int u, int v,int w = 1){
		nodes[u].AL.push_back( make_pair(v,w) );
		nodes[v].AL.push_back( make_pair(u,w) );  /*  Comment this line if directed graph */
	}
	vector< int > bfs(int s){/* starting node */
		vector< int > Distance(N+1,-1);
		vector< pair< int , int > >::iterator it;
		queue< int > Q;
		Q.push(s);
		Distance[s] = 0;
		while(!Q.empty()){
			int u = Q.front(); Q.pop();
			for( it = nodes[u].AL.begin(); it!=nodes[u].AL.end();it++){
				if(  Distance[it->first] == -1 ){
				Distance[it->first] = Distance[u] + it->second;
					Q.push(it->first);
				}
			}
		}
		return Distance;
	}
};	

 int main(){
	lld n,m,i,j,l,r,k,p,d;
	vi a;
	Graph g(6);
	g.add(1,2);
	g.add(1,3);
	g.add(1,6);
	g.add(2,4);
	g.add(3,5);
	g.add(3,6);+


	a = g.bfs(1);
	show(a);

	return 0; 	
 }














