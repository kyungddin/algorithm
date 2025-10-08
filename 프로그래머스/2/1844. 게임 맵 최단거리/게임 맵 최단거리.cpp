#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int answer = 1;
vector<vector<int>> visit;
int row, col;
int gy, gx;

vector<int> dy = {1, -1, 0, 0};
vector<int> dx = {0, 0, 1, -1};

void BFS(vector<vector<int>>& maps){
    queue<tuple<int,int,int>> q;
    q.push({0, 0, 1});
    
    while(!q.empty()){
        tuple<int, int, int> tmp = q.front(); // vector보다 tuple이 시간이 빠르다!
        int ny = get<0>(tmp); // tuple의 각 요소에 접근할 때는 다음과 같이 get<>()을 사용!
        int nx = get<1>(tmp);
        int c = get<2>(tmp);
        q.pop();

        for(int i=0; i<4; i++){
            int ty = ny + dy[i];
            int tx = nx + dx[i];

            if(ty<0 || ty>=row || tx<0 || tx>=col) continue;
            if(maps[ty][tx] == 0) continue;
            
            if(ty == gy && tx == gx){
                answer = c+1;
                return;
            }
            if(!visit[ty][tx]){
                visit[ty][tx] = 1;
                q.push({ty, tx, c+1});
            }
        }
    }
    
    if(answer == 1) answer = -1;
}

int solution(vector<vector<int>> maps)
{
    // Variable Setting
    row = maps.size();
    col = maps[0].size();
    
    // Main Logic
    gy = row - 1;
    gx = col - 1;
    visit.assign(row, vector<int>(col, 0)); // 여러 test_case에 대해서 시간초과가 안 나려면 resize 대신 assign으로 초기화를 거쳐야 함!
    
    BFS(maps);
    
    return answer;
}
