#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> element;
vector<int> storage;

void uni(int a, int b);
int find(int num);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i;
	int n, m;
	cin >> n >> m;

	element.resize(n + 1);

	for (i = 1; i <= n; i++) {
		element[i] = i;
	}

	int c, a, b;

	for (i = 0; i < m; i++) {
		cin >> c >> a >> b;
		
		if (c == 0) {
			uni(a, b);
		}
		else if (c == 1) {
			if (find(a) == find(b)) cout << "YES\n";
			else cout << "NO\n";
		}
	}

	return 0;
}

void uni(int a, int b) {
	a = find(a);
	b = find(b);

	if (a != b) element[b] = a;
}

int find(int num) {
	if (num == element[num]) return num;
	else {
		element[num] = find(element[num]);
		return element[num];
	}
}
