#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Node {
     public:
	int id;
	Node(int);
};

Node::Node(int id):id(id) {}

class Graph {
     public:
        int V;
	Graph(int V);
	void addEdge(int, int );
	vector<int> *adj; 
        void topologicalSort();	
	void topologicalSortHelper(int i, bool visited[], stack<int> &s);
};

Graph::Graph(int V):V(V) {
    adj = new vector<int>[V];
}

void Graph::addEdge(int u, int v) { // u and v are connected
  adj[u].push_back(v); 
}
 
void Graph::topologicalSort() {  //int &visited , 
    bool visited[V];
    for(int i=0;i<V;i++)
	visited[i]=0;
    stack<int> s;	

    for(int i=0;i<V; i++) {
	topologicalSortHelper(i, visited, s); 
    }
    while(s.empty() == false ) {
	cout<<s.top();
	s.pop();
    }
}

void Graph::topologicalSortHelper(int i, bool visited[], stack<int> &s) { 
	if(visited[i] == true )
	   return;
	visited[i] = true;
        vector<int>::iterator it;  	
	for( it = adj[i].begin(); it< adj[i].end(); ++it) {
	   if(visited[*it] == false)
		topologicalSortHelper(*it, visited, s); 
	}
	s.push(i);

}
int main() {

  Graph G(7);
  G.addEdge(0,1); 
  G.addEdge(0,6); 
  G.addEdge(1,2); 
  G.addEdge(6,2); 
  G.addEdge(2,3); 
  G.addEdge(2,4); 
  G.addEdge(3,5); 
  G.addEdge(5,4); 



  G.topologicalSort();

}
