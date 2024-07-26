#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
void Dijkstra(vector<vector<pair<int, int>>> &adjList, int source, int n)
{
    vector<int> dist(n, INT_MAX);
    dist[source] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap; // ordered by first element of pair by default
    min_heap.push(make_pair(0, source));
    while (!min_heap.empty())
    {
        int node = min_heap.top().second;
        int distance = min_heap.top().first;
        min_heap.pop();
        if (distance == dist[node])
        {
            int neighbours = adjList[node].size();
            for (int i = 0; i < neighbours; i++)
            {
                int neighbourNode = adjList[node][i].first;
                int weight = adjList[node][i].second;

                if (distance + weight < dist[neighbourNode])
                {
                    min_heap.push(make_pair(distance + weight, neighbourNode));
                    dist[neighbourNode] = distance + weight;
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
    adjList[u].push_back({v, wt}); // an undirected graph
    adjList[v].push_back({u, wt});
}
int main()
{
    int n = 5;
    vector<vector<pair<int, int>>> adjList(n);

    add_edge(adjList, 0, 1, 2);
    add_edge(adjList, 0, 3, 1);
    add_edge(adjList, 1, 2, 4);
    add_edge(adjList, 3, 2, 3);
    add_edge(adjList, 1, 4, 5);
    add_edge(adjList, 2, 4, 1);

    int source = 4;
    Dijkstra(adjList, source, n);
}
