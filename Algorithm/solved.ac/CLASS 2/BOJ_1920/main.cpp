
#include <bits/stdc++.h>

int n, m;

constexpr int MAX = 100001;

int buf[MAX];
int buf2[MAX];

int main()
{

    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        std::cin >> buf[i];
    }

    std::cin >> m;

    for (int i = 0; i < m; ++i)
    {
        std::cin >> buf2[i];
    }

    std::sort(buf, buf + n);

    for (int i = 0; i < m; ++i)
    {
        int left = 0;
        int right = n - 1;

        bool found = false;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (buf[mid] == buf2[i])
            {
                found = true;
                break;
            }

            if (buf[mid] < buf2[i])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        std::cout << found << "\n";
    }

    return 0;
}