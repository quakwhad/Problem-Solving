#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        long long x;
        cin >> x;

        long long sqrt_x = sqrt(x);

        if(x == sqrt_x * sqrt_x) cout << "1 ";
        else cout << "0 ";
    }
    
    return 0;
}