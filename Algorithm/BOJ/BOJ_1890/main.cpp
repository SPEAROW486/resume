#include <bits/stdc++.h>
#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 1890

int n;
long long board[100][100];
long long dp[100][100];  // 경로의 개수를 저장할 dp 배열

int main() {
    FASTIO;
    
    // n 입력받기
    std::cin >> n;
    
    // 게임판 입력받기
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> board[i][j];
        }
    }
    
    // dp 배열 초기화
    dp[0][0] = 1;  // 시작점 경로 수는 1
    
    // dp를 이용한 경로 탐색
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            // 현재 위치에서 갈 수 있는 경우만 탐색
            if (dp[i][j] > 0 && board[i][j] > 0) {
                int move = board[i][j];
                
                // 아래쪽으로 이동 가능한 경우
                if (i + move < n) {
                    dp[i + move][j] += dp[i][j];
                }
                
                // 오른쪽으로 이동 가능한 경우
                if (j + move < n) {
                    dp[i][j + move] += dp[i][j];
                }
            }
        }
    }
    
    // 결과 출력 (도착점의 경로 개수)
    std::cout << dp[n-1][n-1] << '\n';
    
    return 0;
}
