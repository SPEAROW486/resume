
#include <bits/stdc++.h>

constexpr int MAX = 1000001; // 1000001;

int pos[MAX];
int pos_copy[MAX];
int n;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> pos[i];
    }
    memcpy(pos_copy, pos, sizeof(int) * n);
    std::sort(pos_copy, pos_copy + n);

    int uidx = std::unique(pos_copy, pos_copy + n) - pos_copy;
    for (int i = 0; i < n; ++i)
    {
        int f = pos[i];

        int left = 0;
        int right = uidx - 1;

        int count = 0;
        while (left <= right)
        {
            int mid = (left + right) / 2;

            if (pos_copy[mid] < f)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        std::cout << left << " ";
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}