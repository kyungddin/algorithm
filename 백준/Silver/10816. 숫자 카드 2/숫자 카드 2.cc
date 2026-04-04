#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	unordered_map<int, int> hash;
	int tmp;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		hash[tmp]++;
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> tmp;
		cout << hash[tmp] << " ";
	}
}