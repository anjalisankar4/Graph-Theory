#include <bits/stdc++.h>
using namespace std;
bool isBipartite(const vector<vector < int>> &adjList, vector< int > &color, int node)
{
	queue<int> q;
	q.push(node);
	color[node] = 0;
	while (!q.empty())
	{
		int curr = q.front();
		q.pop();
		int neighbours = adjList[curr].size();
		for (int i = 0; i < neighbours; i++)
		{
			int neighbourNode = adjList[curr][i];
			if (color[neighbourNode] == -1)
			{
				q.push(neighbourNode);
				color[neighbourNode] = (color[curr] == 0) ? 1 : 0;
			}
			else if (color[neighbourNode] == color[curr])
			{
				return false;
			}
		}
	}

	return true;
}

void addEdge(vector<vector < int>> &adjList, int x, int y)
{
	adjList[x].push_back(y);
	adjList[y].push_back(x);
}

int main()
{
	int n, m;
	cout << "Enter number of nodes and edges: " << endl;
	cin >> n >> m;
	vector<int> color(n, -1);
	vector<vector < int>> adjList(n);
	cout << "Enter edges: " << endl;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		addEdge(adjList, u, v);

	}

	int flag = 0;
	for (int i = 0; i < n; i++)
	{
		if (color[i] == -1)
		{
			if (isBipartite(adjList, color, i) == false)
			{
				flag = 1;
				break;

			}
		}
	}

	if (flag == 1)
	{
		cout << "Graph is not Bipartite" << "\n";

	}
	else
	{
		cout << "Graph is Bipartite" << "\n";
	}

	return 0;

}