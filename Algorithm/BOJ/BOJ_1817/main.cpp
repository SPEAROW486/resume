
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n, m;
std::stack<int> s;
int ans;

void solve()
{
    // 책을 탑처럼 쌓았으니 위에서부터 뺄수밖에없음
    // 그러므로 스택을 활용
    int remaining_weight = m;
    while (!s.empty())
    {
        const int top = s.top();
        if (remaining_weight - top < 0)
        {
            ++ans;
            remaining_weight = m;
        }
        else
        {
            remaining_weight -= top;
            s.pop();
            if (s.size() == 0)
            {
                ++ans;
            }
        }
    }

    std::cout << ans;
}

int main()
{
    FASTIO;
    std::cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        int book;
        std::cin >> book;
        s.push(book);
    }

    solve();

    // int nn;
    // std::cin >> nn;
    return 0;
}