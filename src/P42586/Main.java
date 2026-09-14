package P42586;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

class Solution {
    public int[] solution(int[] progresses, int[] speeds) {

        // 큐 선언
        Queue<Integer> q = new LinkedList<>();

        // 큐에 들어갈 수 입력
        for(int i=0; i<progresses.length; i++) {
            progresses[i] = 100 - progresses[i];
            int num =  progresses[i] / speeds[i];
            if(progresses[i] % speeds[i] != 0) num++;
            q.add(num);
        }

        // 결과 저장할 동적 배열 선언
        ArrayList<Integer> answer = new ArrayList<>();

        // 큐가 빌 때까지 실행
        while (!q.isEmpty()) {
            int cnt = 1;
            int save = q.poll();

            // 큐가 비어있지 않고, 큐의 처음 수가 save 이하일 때 pop, cnt++
            while (!q.isEmpty() && q.peek() <= save) {
                q.poll();
                cnt++;
            }
            answer.add(cnt);
        }

        // 동적 배열을 기본형 배열로 변환해서 반환하기
        return answer.stream().mapToInt(i -> i).toArray();
    }
}

public class Main {

}
