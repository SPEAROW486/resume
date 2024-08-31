
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n, k; // n == 사람의 수, k == 보성이의 번호
std::vector<int> v;

int main()
{
    FASTIO;
    std::cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        std::cin >> tmp;
        v.push_back(tmp);
    }

    int ans = 0;
    int tmp = 0;
    std::vector<bool> vi(n);
    tmp = v[0];
    while (vi[tmp] != true)
    {
        ans++;
        vi[tmp] = true;
        if (tmp == k)
        {
            std::cout << ans << "\n";
            return 0;
        }
        tmp = v[tmp];
    }
    std::cout << "-1\n";

    // int nn;
    // std::cin >> nn;
    return 0;
}