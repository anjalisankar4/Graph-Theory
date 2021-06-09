#include <bits/stdc++.h>
using namespace std;
bool isCyclic(int node, int parent, vector<vector < int>> &adjList, vector< bool > &visited)
{
	visited[node] = true;
	int neighbours = adjList[node].size();
	for (int i = 0; i < neighbours; i++)
	{
		int neighbourNode = adjList[node][i];
		if (!visited[neighbourNode])
		{
			if (isCyclic(neighbourNode, node, adjList, visited) == true)
			{
				return true;
			}
		}
		else if (neighbourNode != parent)
		{
			return true;
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
	vector<bool> inStack(n, false);
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
			if (isCyclic(i, -1, adjList, visited))
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
	else cout << "Cycle not found" << "\n";
	return 0;
}
