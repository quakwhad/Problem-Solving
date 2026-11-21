## 문제
[43162 네트워크](https://school.programmers.co.kr/learn/courses/30/lessons/43162)

## 풀이

### 풀이에 대한 직관적인 설명
1. 컴퓨터끼리 직접 또는 간접적으로 연결되어 있으면 같은 네트워크이므로, 서로 연결된 컴퓨터 묶음이 몇 개인지를 세는 문제입니다.

2. 인접 행렬로 주어진 computers를 인접 리스트 node로 바꿉니다.

   computers[i][j]가 1이면 i번 컴퓨터와 j번 컴퓨터가 연결되어 있다는 뜻이므로 node[i]에 j를 넣습니다. 근데 자기 자신(i == j)은 항상 1이므로 제외합니다.

3. 0번 컴퓨터부터 n-1번 컴퓨터까지 차례대로 BFS를 시작해 봅니다.

   이미 방문한 컴퓨터라면 다른 네트워크를 탐색하다가 이미 포함된 컴퓨터이므로 0을 반환하고 넘어갑니다.

4. 방문하지 않은 컴퓨터라면 새로운 네트워크의 시작이므로, 이 컴퓨터와 연결된 모든 컴퓨터를 큐로 따라가며 방문 처리하고 1을 반환합니다.

5. BFS가 반환한 값을 cnt에 계속 더하면, 마지막에 cnt가 곧 네트워크의 개수가 됩니다.

### 풀이 도출 과정
1. 한 컴퓨터에서 BFS를 시작하면 그 컴퓨터와 직접 또는 간접으로 연결된 컴퓨터를 전부 한 번에 방문하게 됩니다.

   그래서 BFS를 새로 시작한 횟수가 곧 서로 연결되지 않은 네트워크의 개수와 같다고 생각했습니다.

2. BFS 함수가 방문 여부에 따라 0 또는 1을 반환하도록 해서, 호출하는 쪽에서는 cnt += BFS(...) 한 줄로 개수를 셀 수 있게 했습니다.

3. 방문 처리를 큐에서 꺼낼 때가 아니라 큐에 넣는 시점에 했습니다.

   꺼낼 때 처리하면 같은 컴퓨터가 큐에 여러 번 들어갈 수 있기 때문입니다.

## 복잡도

* 시간복잡도 : O(N^2)

    * 인접 행렬을 인접 리스트로 바꾸는 데 N x N칸을 모두 확인하므로 O(N^2)

    * BFS는 각 컴퓨터를 한 번씩만 큐에 넣고, 컴퓨터마다 연결된 컴퓨터를 확인하므로 전체 간선의 수인 최대 O(N^2)

    * 따라서 시간복잡도는 O(N^2) 입니다.

### 사용한 언어
C++

### 사용한 소스코드
```cpp
#include <string>
#include <queue>

using namespace std;

bool BFS(const vector<vector<int>> &node, vector<char> &visited, int start) {
    if(visited[start]) return 0;

    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int i=0; i<node[cur].size(); i++) {
            if(!visited[node[cur][i]]) {
                q.push(node[cur][i]);
                visited[node[cur][i]] = 1;
            }
        }
    }
    
    return 1;
}

int solution(int n, vector<vector<int>> computers) {
    int cnt = 0;
    vector<char> visited(n,false);

    vector<vector<int>> node(n);

    for(int i=0; i<computers.size(); i++) {
        for(int j=0; j<computers[i].size(); j++) {
            if(i != j && computers[i][j]) node[i].push_back(j);
        }
    }

    for(int i=0; i<node.size(); i++) {
        cnt += BFS(node, visited, i);
    }

    return cnt;
}
```
