
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int main()
{
    int T; // 테스트 케이스의 수
    std::cin >> T;

    while (T--)
    {
        int N; // 후보의 수
        std::cin >> N;

        std::vector<int> votes(N);
        int totalVotes = 0; // 총 득표수
        for (int i = 0; i < N; ++i)
        {
            std::cin >> votes[i];
            totalVotes += votes[i];
        }

        int maxVotes = 0;
        int winner = -1;
        bool tie = false;

        for (int i = 0; i < N; ++i)
        {
            if (votes[i] > maxVotes)
            {
                maxVotes = votes[i];
                winner = i;
                tie = false;
            }
            else if (votes[i] == maxVotes)
            {
                tie = true;
            }
        }

        if (tie)
        {
            std::cout << "no winner" << std::endl;
        }
        else
        {
            if (maxVotes > totalVotes / 2)
            {
                std::cout << "majority winner " << (winner + 1) << std::endl;
            }
            else
            {
                std::cout << "minority winner " << (winner + 1) << std::endl;
            }
        }
    }

    return 0;
}