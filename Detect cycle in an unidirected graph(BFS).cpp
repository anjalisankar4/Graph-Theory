#include <bits/stdc++.h>
using namespace std;
bool isCyclic(int node, vector<vector < int>> &adjList, vector< bool > &visited)
{
	queue<pair<int, int>> q;
	q.push({ node, -1 });
	visited[node] = true;
	while (!q.empty())
	{
		int currNode = q.front().first;
		int parent = q.front().second;
		q.pop();
		int neighbours = adjList[currNode].size();
		for (int i = 0; i < neighbours; i++)
		{
			int neighbourNode = adjList[currNode][i];

			if (!visited[neighbourNode])
			{
				q.push({ neighbourNode, currNode });
				visited[neighbourNode] = true;
			}
			else if (neighbourNode != parent)
			{
				return true;
			}
		}
	}

	return false;
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
	vector<bool> visited(n, false);
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
		if (!visited[i])
		{
			if (isCyclic(i, adjList, visited))
			{
				flag = 1;
				break;
			}
		}
	}

	if (flag == 1)
	{
		cout << "Cycle found" << "\n";

	}
	else
	{
		cout << "Cycle not found" << "\n";
	}

	return 0;

}