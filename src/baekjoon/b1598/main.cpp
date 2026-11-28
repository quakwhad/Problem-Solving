#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    
    cout << (a/4 > b/4 ? a/4-b/4 : b/4-a/4) + (a%4 > b%4 ? a%4-b%4 : b%4-a%4) << '\n';

    return 0;
}