#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, E;
    cin >> n >> E;
    vector<vector<int>> g(n+1);
    vector<char> visited(n+1, false);

    while(E--) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    queue<int> q;
    q.push(1);
    visited[1] = true;

    int cnt = 0;
    while(!q.empty()) {
        int f = q.front();
        q.pop();

        for(int i=0; i<g[f].size(); i++) {
            if(!visited[g[f][i]]) {
                visited[g[f][i]] = true;
                q.push(g[f][i]);
                cnt++;
            }
        }
    }

    cout << cnt << '\n';

    return 0;
}