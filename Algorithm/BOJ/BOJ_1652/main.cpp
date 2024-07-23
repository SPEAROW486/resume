
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

constexpr int MAX = 101;
constexpr char BLANK = '.';
constexpr char BAGGAGE = 'X';

std::string board[MAX];
bool horizon[MAX];
bool vertical[MAX];

int n;

int main()
{
    FASTIO;
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        std::cin >> board[i];
    }

    int ans_horzion = 0;
    int ans_vertical = 0;

    // X..X..X
    // 같으면 1줄에 2자리가 발생한거라서 ㅇㅇ
    for (int i = 0; i < n; ++i)
    {
        int cnt_horizon = 0;
        int cnt_vertical = 0;
        for (int j = 0; j < n; ++j)
        {
            // 가로
            if (board[i][j] != BAGGAGE)
            {
                ++cnt_horizon;
            }

            if (board[i][j] == BAGGAGE || j == n - 1)
            {
                if (cnt_horizon >= 2)
                {
                    ++ans_horzion;
                }
                cnt_horizon = 0;
            }

            // 세로
            if (board[j][i] != BAGGAGE)
            {
                ++cnt_vertical;
            }

            if (board[j][i] == BAGGAGE || j == n - 1)
            {
                if (cnt_vertical >= 2)
                {
                    ++ans_vertical;
                }
                cnt_vertical = 0;
            }
        }
    }

    std::cout << ans_horzion << " " << ans_vertical;
    return 0;
}