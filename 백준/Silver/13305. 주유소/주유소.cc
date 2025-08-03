#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> city;
vector<int> weight;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i;

	int n;
	cin >> n;

	int tmp;
	for (i = 0; i < n - 1; i++) {
		cin >> tmp;
		weight.push_back(tmp);
	}

	for (i = 0; i < n-1; i++) {
		cin >> tmp;
		city.push_back(pair<int, int>(tmp, weight[i]));
	}

	cin >> tmp;
	city.push_back(pair<int, int>(tmp, 0));

	int price = 0;
	int distance = 0;
	int first_city = 0;

	for (i = 1; i < n; i++) {
		if (city[first_city].first >= city[i].first) {
			distance += city[i-1].second;
			price += (city[first_city].first * distance);
			distance = 0;
			first_city = i;
		}
		else {
			distance += city[i - 1].second;
		}
	}

	cout << price;
}