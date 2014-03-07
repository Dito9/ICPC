#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;
// A recursive function used by topologicalSort

// Class to represent a graph
class Graph
{
    int V;    // No. of vertices'

    // Pointer to an array containing adjacency listsList
    list<int> *adj;
    // A function used by topologicalSort
   public: void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);


     // function to add an edge to graph
    void addEdge(int v, int w);

    // prints a Topological Sort of the complete graph
    void topologicalSort();
    bool ciclo();
    Graph(int V);   // Constructor

};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}


void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}


void Graph::topologicalSortUtil(int v, bool visited[], stack<int> &Stack)
{
    // Mark the current node as visited.
    visited[v] = true;

    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            topologicalSortUtil(*i, visited, Stack);

    // Push current vertex to stack which stores result
    Stack.push(v);
}

// The function to do Topological Sort. It uses recursive topologicalSortUtil()
void Graph::topologicalSort()
{
    stack<int> Stack;

    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Call the recursive helper function to store Topological Sort
    // starting from all vertices one by one
    for (int i = 0; i < V; i++)
      if (visited[i] == false)
        topologicalSortUtil(i, visited, Stack);

    // Print contents of stack
    while (Stack.empty() == false)
    {
        cout << Stack.top()+1 << " ";
        Stack.pop();
    }
    cout <<endl;
}

int main(void){

    int cases;
    cin >> cases;
    while(cases--){
    int tam;
    cin >> tam;
    Graph g(tam);

    int e,v;
    v=tam;
    e=0;
    int hint;
    cin >>hint;

    for (int i=0;i<hint;i++){
        int a,b;
        cin >>a >>b;
        g.addEdge(a-1,b-1);
        e++;
    }
    int rpt = pow(2, (e - v +1) ) -1;

      g.topologicalSort();
   /* bool flag = true;
      for (int i=0;i<(int)lista.size()-1;i++){

        flag = g.conexo(lista.[i],lista[i+1]);
        if (!flag){
            cout << "missing hints"<<endl;
            break;
        }
      }
      if (flag){
        for (int i=0;i<(int)lista.size();i++){

        cout << lista.at(i)<<" "<<endl;
      }
     */
      }

    return 0;
}


