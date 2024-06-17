
#include <bits/stdc++.h>

int n;
constexpr int MAX = 10001;
int buf[MAX];
int score[MAX][3];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        std::cin >> buf[i];
    }

    // 계단이 1개면 buf[2]라는 값에 접근할수가 없으므로
    if (n == 1)
    {
        std::cout << buf[1];
        return 0;
    }

    score[1][1] = buf[1];
    score[1][2] = 0;

    score[2][1] = buf[2];
    score[2][2] = buf[1] + buf[2];

    for (int i = 3; i <= n; ++i)
    {
        // score[i][j] == i 계단을 밣을때 연속해서 j개째의 계단을 밣은 상태를 의미..
        score[i][1] = std::max(score[i - 2][1], score[i - 2][2]) + buf[i];
        score[i][2] = score[i - 1][1] + buf[i];
    }

    std::cout << std::max(score[n][1], score[n][2]);

    return 0;
}