#include<iostream>
#include<queue>

using namespace std;
class Graph {
   public:
	int noOfNodes;
	Graph(int);
	void dijkstra(int);
	void addEdge(int, int, int);
	vector<pair<int,int> > *adjacencyList;
	string *path;

};

Graph::Graph(int noOfNodes):noOfNodes(noOfNodes) {
 
  adjacencyList = new vector<pair<int,int> >[noOfNodes];
  path  = new string[noOfNodes];
}

void Graph::addEdge(int u, int v, int weight) {
	adjacencyList[u].push_back(make_pair(v,weight));
	adjacencyList[v].push_back(make_pair(u,weight));

}
void Graph::dijkstra( int start) {

	//priority_queue<int> pq; 
	priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > q;
	int dist[noOfNodes];
	for(int i=0;i<noOfNodes;i++) 
	   dist[i]=INT_MAX;
	dist[start]=0;
	path[start] = "0";
	q.push(make_pair(0,start));
	bool visited[noOfNodes];
	for(int i=0; i<noOfNodes; i++)
	   visited[i] = false;
	while(q.empty() == false ) {
	  pair<int,int> node = q.top();
	  q.pop();
	  for(vector<pair<int,int> >::iterator it=adjacencyList[node.second].begin();it!=adjacencyList[node.second].end(); ++it) {
		if( dist[(*it).first] > dist[node.second] + (*it).second ) {
		   dist[(*it).first] = dist[node.second] + (*it).second;	
		   string s = to_string((*it).first);
		   path[(*it).first] = path[node.second] + s; 
		}
	    	if(!visited[(*it).first])
		   q.push(make_pair((*it).second,(*it).first));
	  }
	  visited[node.second] = true;	
	}
	for(int i=0;i<noOfNodes; i++) 
	   cout<<i<<"  "<< dist[i]<<" "<<path[i]<<"\n"; 
	


}

int main() {
    Graph g(4);
    g.addEdge(0, 1,5);
    g.addEdge(0, 2,3);
    g.addEdge(1, 2,1);
    g.addEdge(1, 3,3);
    g.addEdge(2, 3,5);
    g.dijkstra(0);
/*
    g.addEdge(2, 4,4);
    g.addEdge(2, 5,5);
    g.addEdge(6, 2,6);
*/
}
