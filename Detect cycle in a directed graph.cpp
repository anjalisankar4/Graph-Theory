#include <bits/stdc++.h>
using namespace std;

bool isCyclic(const vector<vector < int>> &adjList, vector< bool > &visited, vector< bool > &inStack, int source)
{
	visited[source] = 1;
	inStack[source] = 1;

	int neighbours = adjList[source].size();
	for (int i = 0; i < neighbours; i++)
	{
		int neighbourNode = adjList[source][i];

		if (!visited[neighbourNode])
		{
			if (isCyclic(adjList, visited, inStack, neighbourNode) == true)
			{
				return true;
			}
		}
		else if (inStack[neighbourNode] == 1) return true;
	}

	inStack[source] = 0;
	return false;
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
	vector<bool> inStack(n, false);
	vector<vector < int>> adjList(n);
	cout << "Enter edges: " << endl;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		add_edge(adjList, u, v);

	}

	int flag = 0;
	for (int i = 0; i < n; i++)
	{
		if (!visited[i])
		{
			if (isCyclic(adjList, visited, inStack, i) == true)
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
