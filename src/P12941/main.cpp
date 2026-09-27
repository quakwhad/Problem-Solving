#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    sort(A.begin(), A.end());
    sort(B.rbegin(), B.rend());
    A[0] *= B[0];
    for(int i=1; i<A.size(); i++) {
        A[i]*=B[i];
        A[i]+=A[i-1];
    }
    
    return A.back();
}