#include <bits/stdc++.h>
using namespace std;

void dfs(const vector<vector < int>> &adjList, vector< bool > &visited, int source)
{
	if (visited[source]) return;
	cout << "visited:" << source << endl;
	visited[source] = true;
	int totalNeighbours = adjList[source].size();
	for (int i = 0; i < totalNeighbours; i++)
	{
		int neighbourNode = adjList[source][i];
		if (visited[neighbourNode] == false)
		{
			dfs(adjList, visited, neighbourNode);
		}
	}
}

void add_edge(vector<vector < int>> &adjList, int u, int v)
{
	adjList[u].push_back(v);
	//adjList[v].push_back(u); for undirected graph
}

int main()
{
	int n, m;
	cout << "Enter number of nodes and edges: " << endl;
	cin >> n >> m;
	vector<bool> visited(n, false);
	vector<vector < int>> adjList(n);
	cout << "Enter edges: " << endl;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		add_edge(adjList, u, v);

	}

	for (int i = 0; i < n; i++)
	{
		dfs(adjList, visited, i);
	}

	return 0;
}