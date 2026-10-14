import java.util.HashMap;
import java.util.Comparator;
import java.util.Arrays;

class Solution {
    public boolean solution(String[] phone_book) {
        Arrays.sort(phone_book, Comparator.comparingInt(String::length));

        HashMap<String, Boolean> m = new HashMap<>();
        
        for(String str : phone_book) {
            for(int i=0; i<=str.length(); i++) {
                if(m.containsKey(str.substring(0,i))) return false;
            }
            m.put(str, true);
        }
        
        return true;
    }
}

public class Main {
    public static void main(String args[]) {
        Solution s = new Solution();
    }
}
