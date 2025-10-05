algorihm 헤더 호출 후 swap함수를 쓰면 vector swap이 용이
swap(arr[0], arr[1]); <- 이런식으로다가


2차원 vector를 건드릴때는 무조건 행/열 기준으로 생각하기
vector<vector<int>> dp(n, vector<int>(m, 0));	// 2차원 초기화는 이런식으로..
