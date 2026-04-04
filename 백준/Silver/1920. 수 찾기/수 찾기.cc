#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

vector<int> list;

bool binary_search(int num);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        list.push_back(tmp);
    }

    sort(list.begin(), list.end());

    int m;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> tmp;
        cout << binary_search(tmp) << "\n";
    }

    return 0;
}

bool binary_search(int num)
{
    int start = 0;
    int end = list.size() - 1;
    int mid = (start + end) / 2;

    while (start <= end)
    {
        if (num == list[mid]) return true;
        else if (num > list[mid])
        {
            start = mid+1;
            mid = (start + end) / 2;
        }
        else if (num < list[mid])
        {
            end = mid-1;
            mid = (start + end) / 2;
        }
    }

    return false;
}

// 0 1 2 3 4 5
// 1 2 3 4 5