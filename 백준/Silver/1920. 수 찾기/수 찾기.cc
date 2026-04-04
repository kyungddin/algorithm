#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> v;

	int tmp;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());

	int m;
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> tmp;
		cout << binary_search(v.begin(), v.end(), tmp) << "\n";
	}
}