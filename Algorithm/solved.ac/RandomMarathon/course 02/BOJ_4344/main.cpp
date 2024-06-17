
#include <bits/stdc++.h>

constexpr int MAX = 1001;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int tc;
    std::cin >> tc;

    while (tc--)
    {
        int n;
        double buf[MAX];
        std::cin >> n;
        double sum = 0.0;
        for (int i = 0; i < n; ++i)
        {
            std::cin >> buf[i];
            sum += buf[i];
        }

        double avg = sum / n;

        double cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            if (buf[i] > avg)
            {
                ++cnt;
            }
        }

        constexpr double point = 1000.0;
        double score = std::round(cnt / n * 100 * point);
        score /= point;
        std::cout << std::fixed;
        std::cout.precision(3);
        std::cout << score << "%\n";
    }

    // int nn;
    // std::cin >> nn;

    return 0;
}