#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> visited;
vector<vector<int>> graph;

void DFS(int s);
void BFS(int s);

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M, V;
	cin >> N >> M >> V;
	graph.resize(N+1); // THIS!
	visited = vector<int>(N + 1, 0); // THIS!

	int A, B;
	for (int i = 1; i <= M; i++)
	{
		cin >> A >> B;
		graph[A].push_back(B);
		graph[B].push_back(A);
	}

	for (int i = 1; i <= N; i++)
	{
		sort(graph[i].begin(), graph[i].end());
	}

	DFS(V);
	cout << "\n";

	fill(visited.begin(), visited.end(), 0); // THIS!

	BFS(V);
}

void DFS(int s)
{
	visited[s] = 1;
	cout << s << " ";

	for (int v : graph[s])
	{
		if (visited[v] == 0)
			DFS(v);
	}
}

void BFS(int s)
{
	visited[s] = 1;

	queue<int> q;
	q.push(s);
	
	while (!q.empty())
	{
		int current = q.front();
		q.pop();
		cout << current << " ";

		for (int v : graph[current])
		{
			if (visited[v] == 0)
			{
				visited[v] = 1;
				q.push(v);
			}
		}
	}
}