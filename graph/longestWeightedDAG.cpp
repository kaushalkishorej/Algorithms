// A C++ program to print topological sorting of a DAG
#include<iostream>
#include <list>
#include <stack>
#include <vector>
#define NINF INT_MIN
using namespace std;
 
// Class to represent a graph
class Graph
{
    int V;    // No. of vertices'
 
    // Pointer to an array containing adjacency listsList
    list<pair<int,int> > *adj;
 
    // A function used by topologicalSort
    void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);
public:
    Graph(int V);   // Constructor
 
     // function to add an edge to graph
    void addEdge(int v, int w, int weight);
 
    // prints a Topological Sort of the complete graph
    void topologicalSort(int );
};
 
Graph::Graph(int V):V(V)
{
    //this->V = V;
    adj = new list<pair<int,int> >[V];
}
 
void Graph::addEdge(int v, int w, int weight)
{   pair<int,int> edge(w,weight);
    adj[v].push_back(edge); // Add w to v’s list.
}
 
// A recursive function used by topologicalSort
void Graph::topologicalSortUtil(int v, bool visited[], 
                                stack<int> &Stack)
{
    // Mark the current node as visited.
    visited[v] = true;
 
    // Recur for all the vertices adjacent to this vertex
    list<pair<int,int> >::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[(*i).first])
            topologicalSortUtil((*i).first, visited, Stack);
 
    // Push current vertex to stack which stores result
    Stack.push(v);
}
 
// The function to do Topological Sort. It uses recursive 
// topologicalSortUtil()
void Graph::topologicalSort(int s)
{
    stack<int> Stack;
    int dist[V];
 
    int maxWtToReachThisNode[V];
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    vector<bool> visited1(0); 
    // Call the recursive helper function to store Topological
    // Sort starting from all vertices one by one
    for (int i = 0; i < V; i++)
      if (visited[i] == false)
        topologicalSortUtil(i, visited, Stack);
 
    // Print contents of stack
/*    while (Stack.empty() == false)
    {
        cout << Stack.top() << " ";
        Stack.pop();
    }
*/
 for (int i = 0; i < V; i++)
        dist[i] = NINF;
    dist[s] = 0;
 
    // Process vertices in topological order
    while (Stack.empty() == false)
    {
        // Get the next vertex from topological order
        int u = Stack.top();
        Stack.pop();
 
        // Update distances of all adjacent vertices
        list<pair<int,int> >::iterator i;
        if (dist[u] != NINF)
        {
          for (i = adj[u].begin(); i != adj[u].end(); ++i) {
             if (dist[(*i).first] < dist[u] + (*i).second) {
                dist[(*i).first] = dist[u] + (*i).second;
	       cout <<(*i).first<<" " << dist[(*i).first] << "\n"  ; 
	     }
	  }
        }
    }
 
    // Print the calculated longest distances
    cout <<"\n";
    for (int i = 0; i < V; i++)
        (dist[i] == NINF)? cout << "INF ": cout << dist[i] << " ";
}

 
// Driver program to test above functions
int main()
{
    // Create a graph given in the above diagram
    Graph g(7);
    g.addEdge(0, 1,1);
    g.addEdge(0, 2,2);
    g.addEdge(2, 3,3);
    g.addEdge(2, 4,4);
    g.addEdge(2, 5,5);
    g.addEdge(6, 2,6);
 /*

    g.addEdge(5, 2,1);
    g.addEdge(5, 0,1);
    g.addEdge(4, 0,1);
    g.addEdge(4, 1,1);
    g.addEdge(2, 3,1);
    g.addEdge(3, 1,1);
*/
    int v=2;
    cout << "Following is a longest path from" << v <<"\n";
    g.topologicalSort(v);
 
    return 0;
}
