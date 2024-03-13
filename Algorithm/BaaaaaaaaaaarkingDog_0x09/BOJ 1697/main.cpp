
#include <bits/stdc++.h>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n, k;
    std::cin >> n >> k;

    if (n == k)
    {
        std::cout << 0;
        return 0;
    }

    constexpr int BUF_LENGTH = 100001;
    int buf[BUF_LENGTH];

    std::fill(buf, buf + BUF_LENGTH, -1);

    std::queue<int> q;
    q.push(n);
    buf[n] = 0;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        int next[3] = {cur - 1, cur + 1, cur * 2};

        for (int nx : next)
        {
            if (nx < 0 || nx >= BUF_LENGTH)
            {
                continue;
            }

            if (buf[nx] != -1)
            {
                continue;
            }

            buf[nx] = buf[cur] + 1;
            if (nx == k)
            {
                std::cout << buf[nx];
                return 0;
            }
            q.push(nx);
        }
    }

    return 0;
}