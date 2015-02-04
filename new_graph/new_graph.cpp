#include "bits/stdc++.h"
using namespace std;

										   /*  START   */

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
#define show(a) tr(a,it){ cout << *it << " "; }
#define rep(n,i) for(int (i)=0;(i)<(n);(i)++)


											/* END */
class comp{
public:
	bool operator()(const pair<int ,int > &lhs , const pair< int,int > &rhs ) const {
		return rhs.second < lhs.second;
	}
};

class node{
public:
	int data;
	vector< pair< int,int > > AL; /*  Adjacency List  */
};

class Graph{
public:	
	int n; /* Number of Nodes */
	vector< node > nodes;
	vector< vector< int > > AM;
	Graph(int N){
		n = N;
		nodes.resize(n+1); /*  1 indexed */
	}
	void add(int u,int v,int w=1){ /* For adding an edge from node u to node v of weight w default = 1 */
		nodes[u].AL.push_back(make_pair(v,w));
		nodes[v].AL.push_back(make_pair(u,w)); /* comment this line if directed  */ 
	}
	vector< int > bfs(int s){
		/* It returns a vector of the depth of nodes from starting node */
		vector< int > Depths(n+1,-1);
		vector< pair< int, int> >::iterator it;  

		Depths[s] = 0; /*  Starting node is at 0 depth */
		queue< int > Q;
		Q.push(s);
		
		while(!Q.empty()){
			int u = Q.front(); Q.pop();
			for(it = nodes[u].AL.begin();it!=nodes[u].AL.end();it++){
				if( Depths[it->first] == -1 ) {
					Depths[it->first] = Depths[u]+1;
					Q.push(it->first);
				}
			}
		}
		return Depths;
	}

	void produceAM(){ /*  Populates Adjacency Matrix   */
		AM.resize(n+1,vector< int >(n+1,-1));
		vector< pair< int , int > >::iterator it;
		for(int i = 1;i<=n;i++) AM[i][i] = 0;		
		for(int i=1;i<=n;i++){
			for(it = nodes[i].AL.begin();it!=nodes[i].AL.end();it++){
				AM[i][it->first] = it->second;
			}
		}
	}


	void printAM(){
		vector< pair< int , int > >::iterator it;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cout << AM[i][j] << "  ";
			}
			cout << endl;
		}
	}


	pair< vector< int > , vector< int > > Dijiktra(int s){ 
		/* Distance and previous of the node i from the starting node   */		
		/* Single Source Shortest Path */		
		
		produceAM();  /* Populates the Adjacency matrix */	
		
		vector< int > Distances(n+1,-1); /* -1 means undefined */
		vector< int > previous(n+1,-1);  
		vector< pair<int,int> >::iterator it;	
		pair< int, int > k; /* temporary node */
		priority_queue< pair< int, int > ,vector< pair<int,int> >, comp > PQ;
		Distances[s] = 0;
		PQ.push(make_pair(s,0));
		bool isSet[n+1];
		memset(isSet,0,sizeof(isSet));
		while(!PQ.empty()){
			k = PQ.top();
			PQ.pop();
			int u = k.first; /*u and w denotes the node with the least distant node from the starting node */
			int w = k.second;

			if( w == Distances[u] ){ 
			/*  
				There can be multiple instances of same node in the priority queue, Only the
				first one will be of minimum distance others must be discarded  
			 */
				isSet[u] = true;
				Distances[u] = w; /* Fixed */ 

				for(it = nodes[u].AL.begin();it!=nodes[u].AL.end();it++){
					if( !isSet[it->first] ){
						if(Distances[it->first] == -1){
							Distances[it->first] = Distances[u] + AM[u][it->first];
							previous[it->first] = u;

						}else{
							if( Distances[it->first] > Distances[u] + AM[u][it->first]  ){
								Distances[it->first] = Distances[u] + AM[u][it->first];
								previous[it->first] = u;
							}
						}
	 					PQ.push(make_pair(it->first,Distances[it->first]));
					}
				}
			}
		}
		return make_pair(Distances,previous);
	}


	vector< vector < int > > floydWarshall(){ /*  All pair shortest path  */
		vector< vector< int > > APSP;
		produceAM();
		APSP = AM;

		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if( APSP[i][j] == -1 ) APSP[i][j] = 1e8;
			}
		}

		for(int k = 1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					APSP[i][j] = min(APSP[i][j],APSP[i][k] + APSP[k][j]);
				}	
			}
		}
		return APSP;
	}	


	vector< int > bellmanFord(int s ){ /*  Single Source Shoortest path in presence of negative edges */
		vector<int> dist(n+1,1e8);
		produceAM();
		vector< pair<int, int> >::iterator it;
		dist[s] = 0;	
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(it = nodes[i].AL.begin();it!=nodes[i].AL.end();it++){
					dist[it->first] = min(dist[it->first], dist[i] + it->second);
				}
			}
		}

		return dist;
	}	

};


int main(){
	vector< int > a;
	Graph g(6);

	g.add(1,2,2);
	g.add(1,3,1);
	g.add(3,4,5);
	g.add(2,6,1);
	g.add(6,3,1);
	g.add(6,5,3);
	g.add(4,5,2);
	g.add(3,5,10);


	// g.produceAM();
	// g.printAM();

	


	// a = g.Dijiktra(1).first;

	// for(int i=1;i<a.size();i++){
	// 	cout << a[i] << endl;
	// }



	vector< vector< int > > APSP;
	APSP = g.floydWarshall();

	for(int i = 1;i<=6;i++){
		for(int j = 1;j<=6;j++){
			cout << APSP[i][j] << " ";
		}
		cout << endl;
	}


	show(g.bellmanFord(1));

	// for(int i=1;i<=6;i++){
	// 	show(bellmanFord(i));
	// }
	return 0; 	
 }














