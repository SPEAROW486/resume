#include <bits/stdc++.h>

int n;
std::vector<int> sp;
std::vector<int> sm;

int main()
{
    std::cin >> n;
    bool exist_zero = false;
    for (int i = 0; i < n; ++i)
    {
        int number = 0;
        std::cin >> number;

        if (number == 0)
        {
            exist_zero = true;
            continue;
        }

        if (number > 0)
        {
            sp.push_back(number);
        }
        else
        {
            sm.push_back(number);
        }
    }

    std::sort(sp.begin(), sp.end(), std::greater<int>());
    std::sort(sm.begin(), sm.end());

    int total = 0;

    // 양수 배열 처리
    for (int i = 0; i < sp.size(); i += 2)
    {
        if (i + 1 < sp.size())
        {
            // 1인 경우는 곱하기보다 더하기가 유리
            if (sp[i] == 1 || sp[i + 1] == 1)
            {
                total += sp[i] + sp[i + 1];
            }
            else
            {
                total += sp[i] * sp[i + 1];
            }
        }
        else
        {
            total += sp[i]; // 마지막 남은 요소 더하기
        }
    }

    // 음수 배열 처리
    for (int i = 0; i < sm.size(); i += 2)
    {
        if (i + 1 < sm.size())
        {
            total += sm[i] * sm[i + 1];
        }
        else if (!exist_zero)
        {
            total += sm[i]; // 마지막 남은 요소 더하기 (0이 없을 경우)
        }
    }

    std::cout << total;

    return 0;
}
