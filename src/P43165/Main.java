import java.util.*;

class P {
    int idx;
    int val;
    
    P(int idx, int val) {
        this.idx = idx;
        this.val = val;
    }
}

class Solution {
    public int solution(int[] numbers, int target) {
        int cnt = 0;

        Queue<P> q = new LinkedList<>();
        q.add(new P(0, numbers[0]));
        q.add(new P(0, -numbers[0]));
        
        while(!q.isEmpty()) {
            P p = q.poll();
            int idx = p.idx;
            int val = p.val;

            if(idx == numbers.length-2) {
                if(val + numbers[idx+1] == target || val - numbers[idx+1] == target) cnt++;
            }
            else {
                q.add(new P(idx + 1, val + numbers[idx+1]));
                q.add(new P(idx + 1, val - numbers[idx+1]));
            }
        }

        return cnt;
    }
}
