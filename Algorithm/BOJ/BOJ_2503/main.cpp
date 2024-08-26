
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n;
constexpr int MAX = 1001;
bool ans[MAX];

std::pair<int, int> get_count(int number1, int number2)
{
    std::string compare1 = std::to_string(number1);
    std::string compare2 = std::to_string(number2);

    int strike = 0;
    int ball = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == j && compare1[i] == compare2[j])
                ++strike;
            if (i != j && compare1[i] == compare2[j])
                ++ball;
        }
    }

    return {strike, ball}; // 스트라이크와 볼의 개수를 반환
}

int main()
{
    FASTIO;
    memset(ans, true, sizeof(ans));

    for (int i = 123; i <= 987; i++)
    {
        std::string tmp = std::to_string(i);

        if (tmp[0] == tmp[1] || tmp[1] == tmp[2] || tmp[0] == tmp[2])
            ans[i] = false;
        if (tmp[0] - '0' == 0 || tmp[1] - '0' == 0 || tmp[2] - '0' == 0)
            ans[i] = false;
    }

    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int number, strike, ball;
        std::cin >> number >> strike >> ball;

        for (int i = 123; i <= 987; i++)
        {
            if (ans[i])
            {
                std::pair<int, int> count = get_count(number, i);
                if (count.first != strike || count.second != ball)
                {
                    ans[i] = false;
                }
            }
        }
    }

    int cnt = 0;
    for (int i = 123; i <= 987; i++)
    {
        if (ans[i])
        {
            ++cnt;
        }
    }

    std::cout << cnt;

    // int nn;
    // std::cin >> nn;
    return 0;
}
