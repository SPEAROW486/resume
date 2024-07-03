#include <iostream>
#include <vector>

int main()
{
    int change;
    std::cin >> change;

    std::vector<int> dp(change + 1, -1);

    dp[2] = 1;
    dp[5] = 1;

    constexpr int coin_count = 2;
    int coins[coin_count] = {2, 5};

    for (int i = 0; i < coin_count; ++i)
    {
        for (int j = coins[i]; j <= change; ++j)
        {
            if (dp[j - coins[i]] != -1)
            {
                dp[j] = dp[j - coins[i]] + 1;
            }
        }
    }

    std::cout << dp[change] << std::endl;

    return 0;
}