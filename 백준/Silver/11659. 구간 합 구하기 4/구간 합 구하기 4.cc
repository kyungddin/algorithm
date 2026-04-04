#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    int tmp;
    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }

    vector<int> sum_arr;
    sum_arr.push_back(v.front());

    for (int i = 1; i < v.size(); i++)
    {
        sum_arr.push_back(sum_arr[i - 1] + v[i]);
    }

    int a, b;
    int result;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        if (a == 1) result = sum_arr[b - 1];
        else result = sum_arr[b-1] - sum_arr[a - 2];

        cout << result << "\n";
    }
}