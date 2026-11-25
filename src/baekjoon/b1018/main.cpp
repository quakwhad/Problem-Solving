#include <iostream>
#include <vector>

using namespace std;

/*
masking 이용하기

8 * 8 * 2 * (50-8+1) * (50-8+1) = 236672
*/
string W[8] = {
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW"
};

string B[8] = {
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB"
};

int masking(const string (&A)[8], const vector<vector<char>> &c, int row_start, int col_start) {
    int cnt = 0;

    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) cnt += A[i][j] == c[row_start+i][col_start+j];
    }

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int result = 65;
    
    vector<vector<char>> v(n, vector<char>(m));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) cin >> v[i][j];
    }

    for(int i=0; i<=n-8; i++) {
        for(int j=0; j<=m-8; j++) {
            result = min(result, masking(W, v, i, j));
            result = min(result, masking(B, v, i, j));
        }
    }

    cout << result << '\n';

    return 0;
}