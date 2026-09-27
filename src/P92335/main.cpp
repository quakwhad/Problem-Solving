#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

// 1. 먼저 n을 k진수로 바꾼 걸 문자열에 저장
// 2. 저장된 문자열을 쭉 읽기
// 3. 0이 나올 때 까지의 수를 소수 판별 -> 소수면 cnt++

string to_base_k(int n, int k) {
    vector<char> str(0);
    while (n >= k) {
        str.push_back((n % k) + '0');
        n /= k;
    }
    str.push_back(n + '0');
    return string(str.rbegin(), str.rend());
}

vector<int> seive() {
    vector<char> isPrime(1e7+1, true);
    vector<int> prime(2,0);
    prime[0] = 2;
    prime[1] = 3;
    
    for(int i=3; i*i<1e7+1; i+=2) {
        for(int j = i*i; j<1e7+1; j+=i) {
            isPrime[j] = false;
        }
    }
    
    for(int i=5; i<1e7+1; i+=2)
        if(isPrime[i]) prime.push_back(i);
    
    return prime;
}

bool isPrime(vector<int> prime, long long n) {
    if(n <= 1) return false;
    int m = upper_bound(prime.begin(), prime.end(), sqrt(n)) - prime.begin();
    for(int i=0; i<m; i++)
        if (!(n % prime[i])) return false;
    
    return true;
}

int solution(int n, int k) {
    string n_base_k = to_base_k(n, k);
    cout << "to_base_k(n, k): " << n_base_k << '\n';
    long long save = 0;
    int cnt = 0;
    vector<int> prime = seive();
    
    for(int i=0; i<n_base_k.size(); i++) {
        if(n_base_k[i] == '0') {
            if(save == 0) continue;
            cout << "save: " << save << '\n';
            if(isPrime(prime, save)) cnt++;
            save = 0;
        }
        save = save * 10 + (n_base_k[i]-'0');
    }
    cout << "save: " << save << '\n';
    if(isPrime(prime, save)) cnt++;
    
    return cnt;
}