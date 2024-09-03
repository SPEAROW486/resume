
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 2075
// pq의 사이즈를 n까지로 제한하고, 최소힙으로

int n;
std::vector<int> v;

int main()
{
    FASTIO;
    std::cin >> n;

    std::priority_queue<int> pq;
    int prev_max = INT_MIN;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int tmp;
            std::cin >> tmp;
            pq.push(-tmp);
            if (pq.size() > n)
            {
                pq.pop();
            }
        }
    }

    std::cout << -pq.top() << "\n";

    // int nn;
    // std::cin >> nn;

    return 0;
}