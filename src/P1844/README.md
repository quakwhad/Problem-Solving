## 문제
[1844 게임 맵 최단거리](https://school.programmers.co.kr/learn/courses/30/lessons/1844)

## 풀이

### 풀이에 대한 직관적인 설명
1. 상대 팀 진영까지 가는 최단 거리를 구하는 문제이므로 BFS를 사용했습니다.

   BFS는 가까운 칸부터 차례대로 훑기 때문에 도착점에 처음 닿는 순간이 곧 최단 거리가 되는 그런 방식입니다.

2. 큐에는 좌표뿐만 아니라 그 좌표까지 오는 데 걸린 거리도 같이 들고 다녀야 하므로 r, c, d를 가지는 Info 클래스를 만들었습니다.

3. 시작점은 항상 (0,0)이고 문제에서 시작 칸도 1칸으로 세기 때문에 큐에 {0,0,1}을 넣고 (0,0)을 방문 처리합니다.

4. 그 다음에 큐에서 하나씩 꺼내면서 동, 서, 남, 북 네 방향으로 갈 수 있는 칸을 큐에 삽입합니다.

   근데 만약에 다음 좌표가 도착점이라면 더 볼 필요가 없으므로 save.d + 1을 바로 반환하고 끝냅니다.

5. 도착점이 아니라면 맵 밖으로 나가는지, 벽(0)인지, 이미 지나온 칸인지를 확인해서 하나라도 걸리면 넘어가고, 아니면 거리를 1 늘려 큐에 삽입한 뒤 방문 처리를 합니다.

6. 큐가 다 빌 때까지 도착점에 닿지 못했다면 갈 수 있는 길이 아예 없다는 뜻이므로 -1을 반환합니다.

### 풀이 도출 과정
1. 칸을 하나 옮기는 비용이 전부 1로 똑같기 때문에 다익스트라까지 갈 필요 없이 BFS만으로 충분하다고 판단했습니다.

2. 방문 처리를 큐에서 꺼낼 때가 아니라 큐에 넣는 시점에 했습니다.

   꺼낼 때 처리하면 같은 칸이 큐에 여러 번 들어가서 중복으로 방문하게 되기 때문입니다.

3. 격자의 최대 크기가 100x100이므로 방문 배열도 넉넉하게 101x101로 선언했습니다.

4. maps는 maps[세로][가로] 순서로 들어오는데 저는 nr을 가로, nc를 세로로 잡았기 때문에 실제로 맵을 참조할 때는 maps[nc][nr]처럼 순서를 뒤집어서 접근했습니다.

## 복잡도

* 시간복잡도 : O(NM)

    * 방문 처리 덕분에 각 칸은 최대 한 번씩만 큐에 들어가고 나옵니다.

    * 칸마다 4방향을 확인하지만 4는 상수이므로 무시할 수 있습니다.

    * 따라서 시간복잡도는 맵의 칸 수인 O(NM) 입니다.

### 사용한 언어
Java

### 사용한 소스코드
```
import java.util.LinkedList;
import java.util.Queue;

class Info {
    // r: row, c: column, d: distance
    int r, c, d;

    public Info(int r, int c, int d) {
        this.r = r;
        this.c = c;
        this.d = d;
    }
}

class Solution {
    public int solution(int[][] maps) {
        // 맵의 가로 길이
        int row = maps[0].length;

        // 맵의 세로 길이
        int col = maps.length;

        // 격자 최대 크기가 100x100이므로 이미 지나친 격자를 체크하는 2차원 배열도 100x100으로 선언
        boolean[][] visited = new boolean[101][101];

        // BFS 사용을 위한 큐 선언
        Queue<Info> q = new LinkedList<>();

        // 현재 위치에서 갈 수 있는 방향을 큐에 넣을건데 갈 수 있는 방향이 4방위이므로 크기가 4인 배열 2개 선언
        // 2차원 배열로 대체 가능
        // 동 서 남 북
        int[] dx = {1,-1,0,0};
        int[] dy = {0,0,1,-1};

        // 항상 (0,0)에서 시작하고, 처음 시작 거리가 1이므로 큐에 {0,0,1} 삽입
        q.add(new Info(0,0,1));
        // (0,0)을 방문했으므로 방문 처리
        visited[0][0] = true;

        while (!q.isEmpty()) {
            // 큐의 처음 저장할 save 선언
            Info save = q.poll();

            // 다음에 갈 수 있는 경우를 큐에 삽입
            for(int i=0; i<4; i++) {
                int nr = save.r + dx[i]; // 추가될 row
                int nc = save.c + dy[i]; // 추가될 col

                // 추가될 좌표가 도착점이라면 save.d+1을 반환 후 종료
                if (nr == row-1 && nc == col-1) return save.d + 1;

                // 추가될 좌표가 맵 밖이라면 pass
                if(nr < 0 || nr >= row || nc < 0 || nc >= col) continue;

                // 추가될 좌표가 벽이나 이미 간 곳이라면 pass
                if(maps[nc][nr] == 0 || visited[nc][nr]) continue;

                // 위 조건에 만족하지 않는다면 큐에 삽입 후, 방문처리
                q.add(new Info(nr,nc,save.d+1));
                visited[nc][nr] = true;
            }
        }

        return -1;
    }
}
```
