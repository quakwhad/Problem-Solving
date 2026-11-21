#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;

        vector<int> cursor(n);
        queue<pair<int, int>> q;    // {우선순위, 인덱스}
        for(int i=0; i<n; i++) {
            cin >> cursor[i];
            q.push({cursor[i], i});
        }
        
        sort(cursor.begin(), cursor.end());
        
        int cnt = 0;

        while (!q.empty()) {
            if(q.front().first == cursor.back()) {
                cnt++;
                if(q.front().second == m) {
                    cout << cnt << '\n';
                    break;
                }
                q.pop();
                cursor.pop_back();
            }
            else {
                q.push(q.front());
                q.pop();
            }
        }
    }
    
    return 0;
}
