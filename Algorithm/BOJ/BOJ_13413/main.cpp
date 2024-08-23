
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int tc;

int main()
{
    // FASTIO;

    std::cin >> tc;
    while (tc--)
    {
        int n;
        std::cin >> n;

        std::string start;
        std::string end;

        std::cin >> start;
        std::cin >> end;

        int wtob = 0;
        int btow = 0;
        for (int i = 0; i < n; ++i)
        {
            if (start[i] == 'W' && end[i] == 'B')
            {
                ++wtob;
            }
            else if (start[i] == 'B' && end[i] == 'W')
            {
                ++btow;
            }
        }

        // 바꿔야 되는 횟수가 같다면 스왑한거나 마찬가지인거고
        // 둘중에 큰게 있으면 스왑으로 안되고 뒤집어야하는 경우가 있는것.
        std::cout << std::max(wtob, btow) << "\n";
    }

    int nn;
    std::cin >> nn;
    return 0;
}