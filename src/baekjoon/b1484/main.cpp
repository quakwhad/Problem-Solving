#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int G;
    cin >> G;

    vector<int> result(0);

    for(int i=1; i*i < G; i++) {
        if(G % i != 0) continue;

        if((G/i + i) % 2 == 0) result.push_back((G/i + i)/2);
    }

    if(result.empty()) {
        cout << "-1\n";
        return 0;
    }

    for(int i=result.size()-1; i>=0; i--) cout << result[i] << '\n';

    return 0;
}