#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    int dp[16] = {2,};
    
    for(int i=1; i<=n; i++) {
        dp[i] = dp[i-1]*2-1;
        if(i == n) cout << dp[i] * dp[i] << '\n';
    }
    
    return 0;
}
