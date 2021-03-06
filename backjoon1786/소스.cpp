#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#pragma warning(disable:4996)
using namespace std;

#define MOD 1000000000

//Rabin Karp
// 부호 상관없는 정수 n이 주어지면 모듈라 정수계 속의 값을 리턴
inline int mod(long long n) {
    if (n >= 0) return n % MOD;
    return ((-n / MOD + 1) * MOD + n) % MOD; // 음수일 경우
}

int main() {
    string S, W;
    int M, N;

    getline(cin, S);
    getline(cin, W);

    N = S.length();
    M = W.length();

    vector<int> result;
    int G = 0, H = 0, power = 1;
    for (int i = 0; i <= N - M; i++) {
        // W와 S 첫 위치의 해시값을 계산
        if (i == 0) {
            for (int j = 0; j < M; j++) {
                G = mod(G + 1LL * W[M - 1 - j] * power);
                H = mod(H + 1LL * S[M - 1 - j] * power);
                if (j < M - 1) power = mod(power * 2);
            }
        }
        // 아닐 경우 이전 위치의 해시값을 사용해 이번 해시값을 얻음
        else H = mod(2 * (H - 1LL * S[i - 1] * power) + S[i + M - 1]);

        // 해시값이 같다면 단순 비교
        if (G == H) {
            bool same = true;
            for (int j = 0; j < M; j++) {
                if (S[i + j] != W[j]) {
                    same = false;
                    break;
                }
            }
            // 단순 비교해서 문자열을 찾았다면 결과에 추가
            if (same) result.push_back(i + 1);
        }
    }

    // 결과 출력
    printf("%d\n", result.size());
    for (int i : result)
    {
        printf("%d ", i);
    }
     
    return 0;
}