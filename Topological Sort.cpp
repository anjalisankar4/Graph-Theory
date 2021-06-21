#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void topoSort(vector<vector < int>> &adjList, vector< bool > &visited, stack< int > &st, int node)
{
	visited[node] = true;
	int neighbours = adjList[node].size();
	for (int i = 0; i < neighbours; i++)
	{
		int neighbourNode = adjList[node][i];
		if (!visited[neighbourNode])
		{
			topoSort(adjList, visited, st, neighbourNode);
		}
	}

	st.push(node);
}

void addEdge(vector<vector < int>> &adjList, int u, int v)
{
	adjList[u].push_back(v);
}

int main()
{
	int n, m;
	cout << "Enter number of nodes and edges: " << endl;
	cin >> n >> m;
	vector<int> color(n, -1);
	vector<vector < int>> adjList(n);
	vector<bool> visited(n, false);
	cout << "Enter edges: " << endl;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		addEdge(adjList, u, v);

	}

	stack<int> st;
	for (int i = 0; i < n; i++)
	{
		if (!visited[i])
		{
			topoSort(adjList, visited, st, i);
		}
	}

	vector<int> res;
	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
}