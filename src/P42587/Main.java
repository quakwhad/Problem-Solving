import java.util.*;

class Solution {
    public int solution(int[] priorities, int location) {
        int size = priorities.length;
        int[] check = new int[10];
        int cur = 9;
        
        for (int i : priorities) check[i]++;
        
        for (int i = 0; cur > 0; i++) {
            if (i == size) i %= size;
            
            // 커서 업데이트
            while (check[cur] == 0) cur--;
            
            if (priorities[i] == cur) {
                check[cur]--;
                ++check[0];
            }
            
            if (cur == priorities[i] && i == location) return check[0];
        }
        
        return -1;
    }
}
