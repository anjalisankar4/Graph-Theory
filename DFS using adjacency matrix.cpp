#include <bits/stdc++.h>
using namespace std;

void dfs(const vector<vector < int>> &adjMatrix, vector< bool > &visited, int source, int n)
{
	cout << "visited:" << source << endl;
	visited[source] = 1;
	for (int i = 0; i < n; i++)
	{
		int neighbourPresent = adjMatrix[source][i];
		if (neighbourPresent == 1 && !visited[i])
		{
			dfs(adjMatrix, visited, i, n);
		}
	}
}

void add_edge(vector<vector < int>> &adjMatrix, int u, int v)
{
	adjMatrix[u][v] = 1;
	//adjMatrix[v][u]=1; if it is an undirected graph.
}

int main()
{
	int n, m;
	cout << "Enter number of nodes and edges: " << endl;
	cin >> n >> m;
	vector<bool> visited(n, false);
	vector<vector < int>> adjMatrix(n, vector<int> (n, 0));
	cout << "Enter edges: " << endl;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		add_edge(adjMatrix, u, v);

	}

	for (int i = 0; i < n; i++)
	{
		if (!visited[i])
		{
			dfs(adjMatrix, visited, i, n);
		}
	}

	return 0;

}