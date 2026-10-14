#include <iostream>

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
phone_book의 크기가 1 이상 1,000,000 이하이므로 O(N)이여야 한다.
*/

bool compare(const string &a, const string &b) {
    return a.size() < b.size();
}

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end(), compare);

    unordered_map<string, bool> m;

    for(const string &str : phone_book) {
        for(int i=0; i<str.size(); i++) {
            if(m.count(str.substr(0,i))) return false;
        }
        m[str] = 1;
    }

    return true;
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
    vector<pair<bool, bool>> testcase = {
        {solution({"119", "97674223", "1195524421"}), false},
        {solution({"123","456","789"}), true},
        {solution({"12","123","1235","567","88"}), false}
    };

    printCheck(testcase);
}
