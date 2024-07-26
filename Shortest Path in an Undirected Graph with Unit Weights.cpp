#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

void shortDist(vector<vector<int>> &adjList, int n, int source)
{
    vector<int> dist(n, INT_MAX); // to store the distance of each node from source
    queue<int> q;
    q.push(source);
    dist[source] = 0; // distance from source to source is 0.
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        int neighbours = adjList[node].size();
        for (int i = 0; i < neighbours; i++)
        {
            int neighbourNode = adjList[node][i];
            if (dist[node] + 1 < dist[neighbourNode])
                q.push(neighbourNode);
                dist[neighbourNode] = dist[node] + 1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << dist[i] << " ";
    }
}

void add_edge(vector<vector<int>> &adjList, int u, int v)
{
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}
int main()
{
    int n = 9;
    vector<vector<int>> adjList(n);
    add_edge(adjList, 0, 1);
    add_edge(adjList, 0, 3);
    add_edge(adjList, 1, 3);
    add_edge(adjList, 1, 2);
    add_edge(adjList, 3, 4);
    add_edge(adjList, 2, 6);
    add_edge(adjList, 4, 5);
    add_edge(adjList, 5, 6);
    add_edge(adjList, 6, 7);
    add_edge(adjList, 7, 8);
    add_edge(adjList, 6, 8);

    int source = 0;
    shortDist(adjList, n, source);
}
