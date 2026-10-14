#include <iostream>

#include <string>
#include <queue>

using namespace std;

bool BFS(const vector<vector<int>> &node, vector<char> &visited, int start) {
    if(visited[start]) return 0;

    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int i=0; i<node[cur].size(); i++) {
            if(!visited[node[cur][i]]) {
                q.push(node[cur][i]);
                visited[node[cur][i]] = 1;
            }
        }
    }
    
    return 1;
}

int solution(int n, vector<vector<int>> computers) {
    int cnt = 0;
    vector<char> visited(n,false);

    vector<vector<int>> node(n);

    for(int i=0; i<computers.size(); i++) {
        for(int j=0; j<computers[i].size(); j++) {
            if(i != j && computers[i][j]) node[i].push_back(j);
        }
    }

    for(int i=0; i<node.size(); i++) {
        cnt += BFS(node, visited, i);
    }

    return cnt;
}

template <typename T>
bool check(const pair<T, T> &p) {
    return p.first == p.second;
}

template <typename T>
void printCheck(const vector<pair<T, T>> &v) {
    for (int i = 0; i < (int)v.size(); i++) {
        cout << "testcase " << i + 1 << ": ";
        cout << (check(v[i]) ? "정답!\n" : "오답!\n");
    }
}

int main() {
    vector<pair<int, int>> testcase = {
        {solution(3, {{1,1,0}, {1,1,0}, {0,0,1}}), 2},
        {solution(3, {{1,1,0}, {1,1,1}, {0,1,1}}), 1},
    };

    printCheck(testcase);
}
