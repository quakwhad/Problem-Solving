#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> v(3);
    
    while(true) {
        cin >> v[0] >> v[1] >> v[2];
        if(!v[0] && !v[1] && !v[2]) return 0;
        sort(v.begin(), v.end());

        if(v[0] == v[2]) cout << "Equilateral\n";
        else if(v[0] + v[1] <= v[2]) cout << "Invalid\n";
        else if(v[0] == v[1] || v[1] == v[2]) cout << "Isosceles\n";
        else cout << "Scalene\n";
    }

    return 0;
}