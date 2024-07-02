
#include <bits/stdc++.h>

constexpr int MAX = 200001; // 200001;
constexpr int FRUIT_TYPES = 10;

int n;
int fruit[MAX];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> fruit[i];
    }

    int left = 0;
    int right = 0;
    int ans = 0;
    std::unordered_map<int, int> map;
    while (right < n)
    {
        map[fruit[right]]++;

        while (map.size() > 2)
        {
            map[fruit[left]]--;
            if (map[fruit[left]] == 0)
            {
                map.erase(fruit[left]);
            }
            ++left;
        }
        ++right;
        ans = std::max(ans, right - left);
    }

    std::cout << ans;

    // int nn;
    // std::cin >> nn;
    return 0;
}