
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n;

int main()
{
    FASTIO;
    std::cin >> n;

    std::vector<int> ans;
    for (int i = 1; i <= n; ++i)
    {
        int num1 = n;
        int num2 = i;
        int tmp = 0;
        std::vector<int> v = {num1, num2};
        while (true)
        {
            tmp = num1 - num2;
            if (tmp < 0)
            {
                break;
            }
            else
            {
                v.push_back(tmp);
                num1 = num2;
                num2 = tmp;
            }
        }
        if (v.size() > ans.size())
        {
            ans = v;
        }
    }

    std::cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); ++i)
    {
        std::cout << ans[i] << " ";
    }

    int nn;
    std::cin >> nn;
    return 0;
}