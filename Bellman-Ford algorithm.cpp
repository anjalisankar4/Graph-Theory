#include <bits/stdc++.h>
using namespace std;
struct edges
{
	int u;
	int v;
	int wt;
};
int main()
{
	int n, e, source;
	cout << "Enter number of nodes,edges and the source:" << "\n";
	cin >> n >> e >> source;

	vector<edges> vec;
	
	vector<int> dist(n, 1e7);
	dist[source] = 0;
	
	cout << "Enter edges" << "\n";
	for (int i = 0; i < e; i++)
	{
		int u, v, wt;
		cin >> u >> v >> wt;
		vec.push_back({ u, v, wt });
	}

	for (int i = 1; i <= n - 1; i++)
	{
		for (auto it: vec)
		{
			if (dist[it.u] + it.wt < dist[it.v])
			{
				dist[it.v] = dist[it.u] + it.wt;
			}
		}
	}

	int flag = 0;
	for (auto it: vec)
	{
		if (dist[it.u] + it.wt < dist[it.v])
		{
			flag = 1;
		}
	}

	if (flag == 1)
	{
		cout << "Negative cycle detected" << "\n";
	}
	else
	{
		cout << "Shortest distance from source " << source << " is: " << "\n";
		for (int i = 0; i < n; i++)
		{
			cout << "Node " << i << " : " << dist[i] << "\n";
		}
	}
}