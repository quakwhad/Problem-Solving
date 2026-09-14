package P1844;

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

public class Main {

}
