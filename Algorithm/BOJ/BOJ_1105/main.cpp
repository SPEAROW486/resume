
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int l, r;

int main()
{
    FASTIO;
    std::cin >> l >> r;

    // l <= n < r
    // 저 조건을 만족하는 n 중에서 8이 제일 적게 들어있는 수의 8의 개수임.

    // 자리수를 비교해야 하는거 까진 생각했는데
    // 그 뒤를 잘 생각이 안나네
    // 그리디는 일단 탐욕적인 선택이 무엇인가에 대해 생각하는거에 익숙해지는게 먼저인거 같음.

    std::string min_string = std::to_string(l);
    std::string max_string = std::to_string(r);

    int min = min_string.length();
    int max = max_string.length();

    int ans = 0;
    if (min != max)
    {
        // 자리수가 다르면 8이 아예 안들어가는 케이스가 최소 1개는 존재하는듯
        ans = 0;
    }
    else
    {
        if (min_string == max_string)
        {
            for (int i = 0; i < min; ++i)
            {
                if (min_string[i] == '8')
                {
                    ++ans;
                }
            }
        }
        else
        {
            for (int i = 0; i < min; ++i)
            {
                if (min_string[i] != max_string[i])
                {
                    for (int j = 0; j < i; ++j)
                    {
                        if (min_string[j] == '8')
                        {
                            ++ans;
                        }
                    }
                    break;
                }
            }
        }
    }

    std::cout << ans;

    // int nn;
    // std::cin >> nn;
    return 0;
}