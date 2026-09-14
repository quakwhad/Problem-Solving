## 문제
[42586 기능개발](https://school.programmers.co.kr/learn/courses/30/lessons/42586)

## 풀이

### 풀이에 대한 직관적인 설명
1. 각 기능이 완성되기까지 며칠이 걸리는지를 먼저 구합니다.

   남은 작업량은 100 - progresses[i]이고, 이걸 하루 작업량인 speeds[i]로 나누면 걸리는 날이 나옵니다.

2. 근데 나눠떨어지지 않으면 하루가 더 필요하므로 1을 더해줍니다.

   남은 작업량이 5이고 속도가 2라면 2일로는 부족하고 3일이 필요한 것처럼 말이죠

3. 기능은 앞에 있는 것이 끝나야 뒤에 있는 것도 같이 나갈 수 있으므로 걸리는 날을 순서대로 큐에 삽입합니다.

4. 그 다음에 큐에서 하나를 꺼내 기준이 되는 save로 삼고, cnt를 1로 둡니다.

   근데 만약에 큐의 처음 수가 save 이하라면 이 기능은 기준이 되는 기능과 같은 날 배포된다는 뜻이므로 큐를 pop하고 cnt를 늘립니다.

5. 위 과정을 큐가 빌 때까지 반복하면 cnt가 쌓인 순서가 곧 각 배포마다 나가는 기능의 개수가 됩니다.

### 풀이 도출 과정
1. 앞의 기능이 끝나지 않으면 뒤의 기능은 완성되어도 배포될 수 없는데, 이게 먼저 들어온 것이 먼저 나가는 구조와 똑같기 때문에 큐를 사용했습니다.

2. 진도율과 속도를 그대로 들고 비교하면 매 순간 진도를 더해가며 확인해야 해서 번거롭습니다.

   그래서 "며칠 걸리는지"라는 하나의 수로 미리 바꿔두면 앞의 수와 크기만 비교하면 되기 때문에 계산을 먼저 다 끝내놓았습니다.

3. 남은 작업량을 담을 배열을 새로 만들지 않고 progresses 배열을 그대로 덮어써서 사용했습니다.

4. 배포가 총 몇 번 일어날지는 미리 알 수 없기 때문에 결과는 동적 배열에 담은 뒤, 마지막에 기본형 배열로 변환해서 반환했습니다.

## 복잡도

* 시간복잡도 : O(N)

    * 걸리는 날을 계산하면서 배열을 한 번 순회하기 때문에 O(N)

    * 각 기능은 큐에 한 번 삽입되고 한 번 삭제되기 때문에 O(N)

    * 따라서 시간복잡도는 O(N) 입니다.

### 사용한 언어
Java

### 사용한 소스코드
```
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
```
