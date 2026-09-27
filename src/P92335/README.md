## 문제
[92335 k진수에서 소수 개수 구하기](https://school.programmers.co.kr/learn/courses/30/lessons/92335)

## 풀이

### 풀이에 대한 직관적인 설명
1. 먼저 n을 k진수로 바꾼 결과를 문자열로 저장합니다.

   n을 k로 나눈 나머지를 계속 뒤에 붙이다가, 마지막에 뒤집으면 k진수 문자열이 됩니다.

2. 소수 판별에 쓸 소수 목록을 에라토스테네스의 체로 미리 구해둡니다.

3. 저장된 문자열을 앞에서부터 쭉 읽으면서 0이 아닌 숫자는 save에 이어 붙입니다.

   save = save * 10 + (현재 숫자)처럼 붙이면 k진수 문자열 조각을 10진수로 읽은 수가 됩니다.

4. 근데 0을 만나면 지금까지 모은 save가 하나의 후보가 되므로 소수인지 판별하고, 소수라면 cnt를 늘린 뒤 save를 0으로 초기화합니다.

   0이 연속으로 나와서 save가 0이라면 판별할 수가 없으므로 그냥 넘어갑니다.

5. 문자열이 0으로 끝나지 않으면 마지막 조각이 save에 남아있으므로 반복문이 끝난 뒤에 한 번 더 판별해줍니다.

### 풀이 도출 과정
1. 문제의 네 가지 조건(0P0, P0, 0P, P)을 하나씩 따질 필요 없이, 결국 0을 기준으로 문자열을 잘랐을 때 나오는 각 조각이 소수인지만 보면 된다는 걸 알 수 있었습니다.

2. 조각을 10진수로 읽으면 수가 꽤 커질 수 있습니다.

   n이 최대 1,000,000이고 k가 3일 때는 13자리까지 나오므로, int 대신 long long으로 save를 저장했습니다.

3. 조각의 최댓값이 약 1.2 × 10^12이므로 그 제곱근은 약 1.1 × 10^6입니다.

   그래서 1e7까지만 체를 쳐 두면, 제곱근 이하의 소수로 나눠떨어지는지만 확인해서 소수를 판별할 수 있습니다.

4. 체는 짝수를 건너뛰고 홀수의 배수만 지웠고, 소수 목록에서 sqrt(n) 이하인 소수의 개수는 upper_bound로 찾았습니다.

## 복잡도

* 시간복잡도 : O(M log log M + L · pi(sqrt(X)))

    * M = 10^7, L = k진수 문자열의 길이, X = 조각의 최댓값

    * pi(x) = x 이하인 소수의 개수 (예: pi(10) = 4, pi(10^6) = 78,498)

    * 에라토스테네스의 체로 소수 목록을 만드는 데 O(M log log M)

    * 문자열을 한 번 순회하며 조각을 만들고, 각 조각마다 sqrt(X) 이하의 소수로 나눠보기 때문에 O(L · pi(sqrt(X)))

    * 조각의 개수는 문자열 길이를 넘지 않고 sqrt(X)도 약 10^6 정도라, 전체 시간은 체를 만드는 과정이 대부분을 차지합니다.

### 사용한 언어
C++

### 사용한 소스코드
```cpp
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
```
