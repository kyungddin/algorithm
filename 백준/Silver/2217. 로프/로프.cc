#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	int tmp;
	vector<int> rope;

	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		rope.push_back(tmp);
	}

	sort(rope.begin(), rope.end());

	int current;
	int result = rope[0] * N;
	for (int i = 1; i < N; i++)
	{
		if (rope[i] == rope[i - 1]) continue;

		current = rope[i] * (N - i);

		if (current > result) result = current;
	}

	cout << result << "\n";
}