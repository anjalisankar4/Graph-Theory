#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

void topoSort(vector<vector<pair<int, int>>> &adjList, int n, int node, vector<bool> &visited, stack<int> &st)
{
    visited[node] = true;
    int neighbours = adjList[node].size();
    for (int i = 0; i < neighbours; i++)
    {
        int neighbourNode = adjList[node][i].first;
        if (!visited[neighbourNode])
        {
            topoSort(adjList, n, neighbourNode, visited, st);
        }
    }
    st.push(node);
}

void shortDist(vector<vector<pair<int, int>>> &adjList, int source, int n)
{
    vector<bool> visited(n, false);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            topoSort(adjList, n, i, visited, st);
        }
    }

    vector<int> dist(n, INT_MAX);
    dist[source] = 0;

    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (dist[node] != INT_MAX)
        {
            int neighbours = adjList[node].size();
            for (int i = 0; i < neighbours; i++)
            {
                int neighbourNode = adjList[node][i].first;
                int weight = adjList[node][i].second;
                if (dist[node] + weight < dist[neighbourNode])
                {
                    dist[neighbourNode] = dist[node] + weight;
                }
            }
        }
    }
    cout << "Distance of all nodes from source node:" << source << endl;
    for (int i = 0; i < n; i++)
    {
        if (dist[i] != INT_MAX)
            cout << "node " << i << ": " << dist[i] << ",  ";
        else
            cout << i << " not reachable" << endl;
    }
}
void add_edge(vector<vector<pair<int, int>>> &adjList, int u, int v, int wt)
{
    adjList[u].push_back({v, wt});
}
int main()
{
    int n = 6;
    vector<vector<pair<int, int>>> adjList(n);

    add_edge(adjList, 0, 1, 2); // means there is an edge from 0 to 1 with a weight 2
    add_edge(adjList, 0, 4, 1);
    add_edge(adjList, 1, 2, 3);
    add_edge(adjList, 4, 2, 2);
    add_edge(adjList, 4, 5, 4);
    add_edge(adjList, 5, 3, 1);
    add_edge(adjList, 2, 3, 6);

    int source = 0;
    shortDist(adjList, source, n);
}
