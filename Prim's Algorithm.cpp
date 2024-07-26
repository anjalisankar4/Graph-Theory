#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
void Prims(vector<vector<pair<int, int>>> &adjList, int n)
{
    vector<int> weight(n, INT_MAX);
    vector<bool> MST(n, false);
    vector<int> parent(n, -1);
    weight[0] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
    min_heap.push({0, 0});           // first node(0 indexed)doesn’t have any incoming nodes, so weight 0.
    for (int i = 1; i <= n - 1; i++) // we pick minimum n-1 times.
    {
        int node = min_heap.top().second; // node with minimum weight among all nodes currently in queue.
        min_heap.pop();
        MST[node] = true; // making this node part of MST
        int neighbours = adjList[node].size();
        for (int k = 0; k < neighbours; k++) // iterating through neighbour nodes
        {
            int neighbourNode = adjList[node][k].first;
            int wt = adjList[node][k].second;

            if (wt < weight[neighbourNode] && MST[neighbourNode] == false) 
            {
                weight[neighbourNode] = wt;
                parent[neighbourNode] = node;
                min_heap.push({wt, neighbourNode}); 
            }
        }
    }

    cout << endl;
    for (int i = 1; i < n; i++)
    {
        cout << "node: " << i << " parent: " << parent[i] << endl;
    }
}

void add_edge(vector<vector<pair<int, int>>> &adjList, int u, int v, int wt)
{
    adjList[u].push_back({v, wt}); 
    adjList[v].push_back({u, wt});
}
int main()
{
    int n = 6;
    vector<vector<pair<int, int>>> adjList(n);

    add_edge(adjList, 0, 1, 2);
    add_edge(adjList, 0, 3, 1);
    add_edge(adjList, 0, 4, 4);
    add_edge(adjList, 3, 4, 9);
    add_edge(adjList, 3, 2, 5);
    add_edge(adjList, 3, 1, 3);
    add_edge(adjList, 1, 2, 3);
    add_edge(adjList, 2, 5, 8);
    add_edge(adjList, 1, 5, 7);
    Prims(adjList, n);
}
