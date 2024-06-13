
#include <bits/stdc++.h>

int n;

constexpr int MAX = 1001;
int buf[MAX];
int ans[MAX];

int main()
{
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        std::cin >> buf[i];
    }

    int min_number = *std::min_element(buf, buf + n);
    int max_number = *std::max_element(buf, buf + n);
    for (int i = 2; i <= max_number; ++i)
    {
        ans[i] = i;
    }

    for (int i = 2; i < MAX; ++i)
    {
        int multi = 2;
        while (true)
        {
            int temp = i * multi;

            if (temp >= MAX)
            {
                break;
            }
            ans[temp] = 0;
            ++multi;
        }
    }

    int count = 0;
    for (int i = 0; i < n; ++i)
    {
        int idx = buf[i];
        if (ans[idx] != 0)
        {
            ++count;
        }
    }

    std::cout << count;

    return 0;
}