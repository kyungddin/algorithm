#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int N;
		cin >> N;
		
		int A, B;
		map<int, int> score;
		for (int j = 0; j < N; j++)
		{
			cin >> A >> B;

			score[A] = B;
		}

		int count = 1;
		int tmp = 1;

		for (int j = 2; j <= N; j++)
		{
			if (score[j] < score[tmp])
			{
				count++;
				tmp = j;
			}
		}

		cout << count << "\n";
	}
}