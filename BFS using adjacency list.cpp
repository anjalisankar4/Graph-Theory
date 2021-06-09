#include <bits/stdc++.h>
using namespace std;

void bfs(const vector<vector < int>> &adjList, vector< bool > &visited, int source)
{
	queue<int> q;
	q.push(source);
	visited[source] = 1;
	while (!q.empty())
	{
		int curr = q.front();
		q.pop();
		cout << "visited: " << curr << endl;
		int neighbours = adjList[curr].size();
		for (int i = 0; i < neighbours; i++)
		{
			int neighbourNode = adjList[curr][i];
			if (!visited[neighbourNode])
			{
				q.push(neighbourNode);
				visited[neighbourNode] = 1;
			}
		}
	}
}

void add_edge(vector<vector < int>> &adjList, int u, int v)
{
	adjList[u].push_back(v);

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
		if (!visited[i])
		{
			bfs(adjList, visited, i);
		}
	}

	return 0;

}
