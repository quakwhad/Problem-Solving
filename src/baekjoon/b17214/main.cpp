#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string input;
    cin >> input;

    int idx = 0;

    int sec = 0;
    bool isPos = true;
    bool isOnlyNum = true;

    size_t pos = 0;
    stoi(input, &pos);
    if (pos != input.length()) isOnlyNum = false;
    
    // 입력이 일차항 이상일 때
    if(!isOnlyNum) {
        while(input[idx] != 'x') {
            if(input[idx] == '-') {
                isPos = false;
                idx++;
                continue;
            }

            sec = sec * 10 + (input[idx] - '0');
            idx++;
        }

        sec >>= 1;

        // 이차항 표현
        if(sec) {
            if(!isPos) cout << '-';
            if (sec != 1) cout << sec;

            cout << "xx";
        }

        idx++;
    }
    

    int first = 0;
    isPos = true;
    while(idx != input.size()) {
        if(input[idx] == '-') {
            isPos = false;
            idx++;
            continue;
        }
        else if(input[idx] == '+') {
            idx++;
            continue;
        }

        first = first * 10 + (input[idx] - '0');
        idx++;
    }

    // 일차항 표현
    if(first) {
        if(!isPos) cout << '-';
        else {
            if(sec) cout << '+';
        }

        if (first != 1) cout << first;

        cout << 'x';
    }

    // W 앞의 부호 표현
    if(sec | first) cout << '+';

    cout << "W\n";

    return 0;
}