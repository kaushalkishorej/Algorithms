#include<iostream>
#include<queue>

using namespace std;
int findMinNode(const int dist[], const bool mstSet[],int noOfNodes ) {
	int min_dist=INT_MAX, min_index;
	for( int i=0; i< noOfNodes; i++) {
	  if(mstSet[i]==false && dist[i] < min_dist) 
		min_dist=dist[i], min_index=i;
	}
	return min_index;
}
void mst(int noOfNodes,int graph[5][5]) {

	int dist[noOfNodes];
	bool mstSet[noOfNodes];
	for(int i=0; i < noOfNodes; i++)
	  dist[i]=INT_MAX,mstSet[i]=false;
	
	int parent[noOfNodes];
	dist[0]=0;
	parent[0]=-1;

	for(int i=0; i<noOfNodes ; i++) {
	  
	  int u = findMinNode(dist,mstSet,noOfNodes);
	  mstSet[u]=true;

	  for(int i=0; i<noOfNodes; i++)
	    if(graph[u][i] && mstSet[i]==false && graph[u][i] < dist[i])
		parent[i]=u, dist[i]=graph[u][i];
	  
	} 	
   for(int i=0; i<noOfNodes; i++)	
	cout<<parent[i]<<"->"<<i<<"\n";
}

int main() {
   int graph[5][5] = {{0, 2, 0, 6, 0},
                      {2, 0, 3, 8, 5},
                      {0, 3, 0, 0, 7},
                      {6, 8, 0, 0, 9},
                      {0, 5, 7, 9, 0},
                     };
	mst(5,graph);
}
