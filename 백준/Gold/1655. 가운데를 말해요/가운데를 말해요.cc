#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	priority_queue<int, vector<int>, greater<int>> min_heap;
	priority_queue<int, vector<int>, less<int>> max_heap;

	int tmp;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;

		if (i == 0)
		{
			max_heap.push(tmp);
			cout << max_heap.top() << "\n";
			continue;
		}

		if (tmp > max_heap.top())
		{
			min_heap.push(tmp);

			if (min_heap.size() > max_heap.size())
			{
				max_heap.push(min_heap.top());
				min_heap.pop();
			}
		}

		else {
			max_heap.push(tmp);

			if (max_heap.size() > min_heap.size()+1)
			{
				min_heap.push(max_heap.top());
				max_heap.pop();
			}
		}

		cout << max_heap.top() << "\n";
	}
}