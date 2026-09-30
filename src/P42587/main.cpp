#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int size = priorities.size();
    int check[10] = {0,};
    int cur = 9;
    
    for(int i : priorities) check[i]++;
    
    for(int i=0; cur > 0; i++) {
        if(i==size) i %= size;
        // 커서 업데이트
        while(!check[cur]) cur--;
        
        if(priorities[i] == cur) {
            check[cur]--;
            ++check[0];
        }
        
        if(cur == priorities[i] && i == location) return check[0];
    }
}