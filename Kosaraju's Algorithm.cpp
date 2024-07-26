#include <iostream>
#include <vector>
#include <stack>
using namespace std;
// topological sort using DFS
void topoSort(vector<vector<int>> &adjList, int node, vector<bool> &visited, stack<int> &st)
{
    visited[node] = true;
    int neighours = adjList[node].size();
    for (int i = 0; i < neighours; i++)
    {

        int neighourNode = adjList[node][i];
        if (!visited[neighourNode])
        {
            topoSort(adjList, neighourNode, visited, st);
        }
    }
    st.push(node);
}
void revDfs(int node, vector<bool> &visited, vector<vector<int>> &transpose)
// DFS from the topological stack order
{
    cout << node << " ";
    visited[node] = true;
    int neighours = transpose[node].size();
    for (int i = 0; i < neighours; i++)
    {
        int neighourNode = transpose[node][i];
        if (!visited[neighourNode])
        {
            revDfs(neighourNode, visited, transpose);
        }
    }
}
void Kosaraju(vector<vector<int>> &adjList, int n)
{
    vector<bool> visited(n, false);
    stack<int> st; // for topological sort

    for (int i = 0; i < n; i++) // if the graph has multiple components
    {
        if (!visited[i])
        {
            topoSort(adjList, i, visited, st);
        }
    }

    vector<vector<int>> transpose(n); // declaring a new matrix to store transpose
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
        int neighours = adjList[i].size();
        for (int j = 0; j < neighours; j++)
        {
            int neighourNode = adjList[i][j];
            transpose[neighourNode].push_back(i);
        }
    }

    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (!visited[node])
        {
            cout << "SCC: "; 
            revDfs(node, visited, transpose);
            cout << endl;
        }
    }
}
void add_edge(vector<vector<int>> &adjList, int u, int v)
{
    adjList[u].push_back(v); // Kosaraju's algorithm is used for only directed graphs
}
int main()
{
    int n = 6;
    vector<vector<int>> adjList(n); // using a vector of vector of pairs to store weights

    add_edge(adjList, 0, 2); // means there is an edge from 0 to 1 with a weight 2
    add_edge(adjList, 2, 1);
    add_edge(adjList, 1, 0);
    add_edge(adjList, 2, 4);
    add_edge(adjList, 4, 3);
    add_edge(adjList, 3, 5);
    add_edge(adjList, 5, 4);
    Kosaraju(adjList, n);
}

