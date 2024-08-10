
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int main()
{
    FASTIO;

    int b, c, d;
    std::cin >> b >> c >> d;

    std::vector<int> bv;
    std::vector<int> cv;
    std::vector<int> dv;
    for (int i = 0; i < b; ++i)
    {
        int tmp;
        std::cin >> tmp;
        bv.push_back(tmp);
    }

    for (int i = 0; i < c; ++i)
    {
        int tmp;
        std::cin >> tmp;
        cv.push_back(tmp);
    }

    for (int i = 0; i < d; ++i)
    {
        int tmp;
        std::cin >> tmp;
        dv.push_back(tmp);
    }

    std::sort(bv.begin(), bv.end(), std::greater<>());
    std::sort(cv.begin(), cv.end(), std::greater<>());
    std::sort(dv.begin(), dv.end(), std::greater<>());

    int ans_before = 0;
    int ans_discount = 0;
    int max_length = std::max({bv.size(), cv.size(), dv.size()});
    for (int i = 0; i < max_length; ++i)
    {
        int cnt = 0;
        int sum = 0;
        if (i < bv.size())
        {
            sum += bv[i];
            ++cnt;
        }

        if (i < cv.size())
        {
            sum += cv[i];
            ++cnt;
        }

        if (i < dv.size())
        {
            sum += dv[i];
            ++cnt;
        }

        ans_before += sum;
        if (cnt == 3)
        {
            sum *= 0.9;
        }

        ans_discount += sum;
    }

    std::cout << ans_before << "\n"
              << ans_discount << "\n";

    // int nn;
    // std::cin >> nn;
    return 0;
}