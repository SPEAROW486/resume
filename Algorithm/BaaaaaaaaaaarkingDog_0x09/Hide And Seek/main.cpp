#include <iostream>
#include <queue>
#include <algorithm>
#include <limits.h>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n, k;
    std::cin >> n >> k;

    constexpr int BUF_LENGTH = 101; // 추후에 100001로 수정해야함.
    int buf[BUF_LENGTH];

    std::fill(buf, buf + BUF_LENGTH, 0);

    int dx[3] = {-1, 1, 2};

    std::queue<int> q;
    q.push(n);

    while (!q.empty())
    {
        // +dx or *dx하면서
        // 방문 체크하고
    }

    return 0;
}