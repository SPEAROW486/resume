
#include <bits/stdc++.h>

int n, m;
constexpr int MAX = 500001; // 500001;

std::string p1[MAX];
std::string p2[MAX];

std::vector<std::string> v;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m;

    // 듣
    for (int i = 0; i < n; ++i)
    {
        std::cin >> p1[i];
    }

    // 보
    for (int i = 0; i < m; ++i)
    {
        std::cin >> p2[i];
    }

    std::sort(p1, p1 + n);
    std::sort(p2, p2 + m);

    // n이 50만이니까 n^2은 안되고
    // 정렬하고 이진탐색하면 될지도?
    for (int i = 0; i < n; ++i)
    {
        const std::string &name = p1[i];

        int left = 0;
        int right = m - 1;

        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (p2[mid] == name)
            {
                v.push_back(p2[mid]);
                break;
            }

            if (p2[mid] > name)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
    }

    std::cout << v.size() << "\n";
    for (const auto &elem : v)
    {
        std::cout << elem << "\n";
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}