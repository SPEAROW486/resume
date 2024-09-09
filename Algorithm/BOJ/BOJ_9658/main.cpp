#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 9658

constexpr int MAX = 1001;
int n;
bool dp[MAX]; // dp[i] == 돌이 i개 있을때 true면 상근이가 승리

int main()
{
    FASTIO;
    std::cin >> n;

    // 상근이가 승리하는 초기 조건
    // 1개 3개 4개 가져갈수있는데 마지막 돌을 가져가는 사람이 지는거니까
    // 상근이가 이기는 초기 조건은 이거임.
    dp[2] = dp[4] = dp[6] = true;

    // 5개 이상일때부터 창영이부터 시작해서
    for (int i = 5; i <= n; ++i)
    {
        // 상근이가 돌을 1개 가져가면, 창영이가 돌이 i - 1개 있는 상태에서 게임을 시작.
        // 상근이가 돌을 3개 가져가면, 창영이가 돌이 i - 3개 있는 상태에서 게임을 시작.
        // 상근이가 돌을 4개 가져가면, 창영이가 돌이 i - 4개 있는 상태에서 게임을 시작.

        // 위 3개 경우에서 창영이가 전부 이기는 상태면 상근이는 못이김
        dp[i] = !(dp[i - 1] && dp[i - 3] && dp[i - 4]);
    }

    if (dp[n])
    {
        std::cout << "SK\n"; // 상근이가 이길 수 있으면 SK
    }
    else
    {
        std::cout << "CY\n"; // 창영이가 이길 수 있으면 CY
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}
