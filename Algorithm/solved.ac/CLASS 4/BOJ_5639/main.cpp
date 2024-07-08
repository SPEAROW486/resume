
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n;
std::vector<int> v;

void post_order(int st, int en)
{
    if (st >= en)
    {
        return;
    }

    if (st == en - 1)
    {
        std::cout << v[st] << "\n";
        return;
    }

    int idx = st + 1;
    while (idx < en)
    {
        if (v[st] < v[idx])
        {
            break;
        }
        ++idx;
    }

    post_order(st + 1, idx);
    post_order(idx, en);
    std::cout << v[st] << "\n";
}

int main()
{
    FASTIO;

    // 루트 -> 왼쪽 -> 오른쪽으로 들어온 순서를 왼쪽 -> 오른쪽 -> 루트로 바꾸기 위해서
    // 루트보다 작은 지점, 루트보다 큰 지점으로 쪼개서 후위순회시킴.

    while (std::cin >> n)
    {
        v.push_back(n);
    }

    post_order(0, v.size());

    // int nn;
    // std::cin >> nn;

    return 0;
}