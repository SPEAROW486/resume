
#include <bits/stdc++.h>

int n;

std::vector<std::pair<int, int>> v;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int start_month, start_day, end_month, end_day;
        std::cin >> start_month >> start_day >> end_month >> end_day;

        v.push_back({start_month * 100 + start_day, end_month * 100 + end_day});
    }
    std::sort(v.begin(), v.end());

    int tmp = 301;
    int end = 1201;
    int count = 0;
    while (tmp < end)
    {
        int ntmp = tmp;

        // 최대한 구간을 넓은걸 택하는거..
        for (const auto &f : v)
        {
            if (f.first <= tmp && f.second > ntmp)
            {
                ntmp = f.second;
            }
        }

        if (ntmp == tmp)
        {
            std::cout << "0\n";
            return 0;
        }

        ++count;
        tmp = ntmp;
    }

    std::cout << count;

    // int nn;
    // std::cin >> nn;
    return 0;
}