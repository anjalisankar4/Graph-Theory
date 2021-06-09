#include <bits/stdc++.h>
using namespace std;

void bfs(const vector<vector < int>> &adjMatrix, vector< bool > &visited, int source, int n)
{
	queue<int> q;
	q.push(source);
	visited[source] = 1;
	while (!q.empty())
	{
		int curr = q.front();
		q.pop();
		cout << "visited: " << curr << endl;
		for (int i = 0; i < n; i++)
		{
			int neighboursPresent = adjMatrix[curr][i];
			if (neighboursPresent == 1 && !visited[i])
			{
				q.push(i);
				visited[i] = 1;
			}
		}
	}
}

void add_edge(vector<vector < int>> &adjMatrix, int u, int v)
{
	adjMatrix[u][v] = 1;
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
			bfs(adjMatrix, visited, i, n);
		}
	}

	return 0;

}