#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 연산 1. *2
	// 연산 2. *10 -> +1

	int A, B;
	int count=0;

	cin >> A >> B;

	while (true)
	{
		if (A > B)
		{
			count = -1;
			break;
		}

		else if ((B - 1) % 10 == 0)
		{
			B = (B - 1) / 10;
			count++;
		}

		else if (B % 2 == 0)
		{
			B = B / 2;
			count++;
		}

		else
		{
			count = -1;
			break;
		}

		if (A == B)
		{
			count++;
			break;
		}
	}

	// 162->81->8->4->2 -> *5*
	// 42 -> 21 -> *-1*

	cout << count << "\n";
}