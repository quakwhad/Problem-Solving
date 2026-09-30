## 문제
[43165 타겟 넘버](https://school.programmers.co.kr/learn/courses/30/lessons/43165)

## 풀이

### 풀이에 대한 직관적인 설명
1. 각 숫자마다 더하거나 빼는 두 가지 선택이 있으므로, 모든 경우를 BFS로 하나씩 만들어 봅니다.

2. 큐에는 지금 몇 번째 숫자까지 사용했는지(idx)와 그때까지 계산된 값(val)을 같이 들고 다녀야 하므로 idx, val을 가지는 구조체 P를 만들었습니다.

3. 처음에는 첫 번째 숫자를 더한 경우와 뺀 경우인 {0, numbers[0]}과 {0, -numbers[0]}을 큐에 삽입합니다.

4. 그 다음에 큐에서 하나씩 꺼내면서 다음 숫자를 더한 값과 뺀 값을 각각 큐에 삽입합니다.

5. 근데 만약에 꺼낸 값이 마지막 바로 앞 숫자까지 계산된 값이라면, 마지막 숫자는 큐에 넣지 않고 바로 더하거나 빼서 target과 비교합니다.

   둘 중 하나라도 target과 같다면 cnt를 늘립니다.

6. 큐가 빌 때까지 반복하면 cnt가 target을 만드는 방법의 수가 됩니다.

### 풀이 도출 과정
1. 숫자의 개수가 최대 20개이므로 모든 경우의 수는 2^20, 약 100만 개입니다.

   전부 확인해도 시간 안에 충분히 들어오기 때문에 완전 탐색으로 풀었습니다.

2. 각 숫자가 최대 50이고 최대 20개이므로 계산되는 값의 범위는 -1,000 ~ 1,000입니다.

   int로 충분히 저장할 수 있습니다.

3. 마지막 숫자까지 큐에 넣고 꺼내서 비교하면 큐에 들어가는 원소가 2배로 늘어나기 때문에, 마지막 숫자는 큐에 넣지 않고 바로 target과 비교했습니다.

4. 한 쌍에서 더한 값과 뺀 값이 둘 다 target이 되려면 마지막 숫자가 0이어야 하는데, 숫자는 1 이상이므로 한 쌍에서 cnt는 최대 1만 늘어납니다.

## 복잡도

* 시간복잡도 : O(2^N)

    * 큐에 들어가는 원소는 2 + 4 + ... + 2^(N-1) = 2^N - 2개입니다.

    * 각 원소는 한 번 삽입되고 한 번 삭제되며, 꺼낼 때마다 하는 일은 상수 시간입니다.

    * 따라서 시간복잡도는 O(2^N) 입니다.

### 사용한 언어
C++

### 사용한 소스코드
```cpp
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
```
