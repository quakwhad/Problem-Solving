#include <queue>

using namespace std;

// BFS
// 큐에 저장되는 값의 범위: -50*20 ~ 50*20 -> int 사용 가능
// 모든 경우의 수: 2^21 - 1개 -> 시간 초과 X
// 인덱스가 마지막일 때는 큐에 값을 넣지 않고, target과 비교하여 cnt++

struct P {
    int idx;
    int val;
};

int solution(vector<int> numbers, int target) {
    int cnt = 0;
    
    queue<P> q;
    // {인덱스, 값}
    q.push({0, numbers[0]});
    q.push({0, -numbers[0]});
    while(!q.empty()) {
        int idx = q.front().idx;
        int val = q.front().val;
        q.pop();
        
        if(idx == numbers.size()-2) {
            if(val + numbers[idx+1] == target || val - numbers[idx+1] == target) cnt++;
        }
        else {
            q.push({idx+1, val + numbers[idx+1]});
            q.push({idx+1, val - numbers[idx+1]});
        }
    }
    
    return cnt;
}