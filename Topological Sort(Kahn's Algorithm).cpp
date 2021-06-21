#include <iostream>
#include <queue>
#include<vector>
using namespace std;
void topoSort(vector<vector < int>> &adjList, int n, vector< int > &inDegree)
{
	vector<int> res;
	queue<int> q;
	for (int i = 0; i < n; i++)
	{
		if (inDegree[i] == 0)
		{
			q.push(i);
		}
	}

	while (!q.empty())
	{
		int node = q.front();
		res.push_back(node);
		q.pop();
		int neighbours = adjList[node].size();
		for (int i = 0; i < neighbours; i++)
		{
			int neighbourNode = adjList[node][i];
			inDegree[neighbourNode]--;
			if (inDegree[neighbourNode] == 0)
			{
				q.push(neighbourNode);
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << res[i] << " ";
	}
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

	vector<int> inDegree(n, 0);
	for (int i = 0; i < n; i++)
	{
		int neighbours = adjList[i].size();
		for (int j = 0; j < neighbours; j++)
		{
			int neighbourNode = adjList[i][j];
			inDegree[neighbourNode]++;
		}
	}

	topoSort(adjList, n, inDegree);

}
