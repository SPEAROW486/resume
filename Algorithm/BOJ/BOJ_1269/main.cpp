
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

std::map<int, bool> map;
int n, m;
int num;
int main(void)
{
    FASTIO;
    std::cin >> n >> m;
    for (int i = 0; i < n + m; i++)
    {
        std::cin >> num;
        if (map[num])
        {
            map.erase(num);
        }
        else
        {
            map[num] = true;
        }
    }
    std::cout << map.size();

    // int nn;
    // std::cin >> nn;
}