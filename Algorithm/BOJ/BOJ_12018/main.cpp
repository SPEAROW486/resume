
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n, m;

int main()
{
    FASTIO;
    std::cin >> n >> m;

    int ans = 0;
    std::priority_queue<int, std::vector<int>, std::greater<>> pq;

    // 무언가 우선적으로 골라야 할 때에는 우선순위 큐를 쓰면 좋다..!
    for (int i = 0; i < n; ++i)
    {
        int p, l;
        std::cin >> p >> l;
        std::vector<int> v;
        v.resize(p);

        for (int j = 0; j < p; ++j)
        {
            std::cin >> v[j];
        }

        std::sort(v.begin(), v.end());

        if (p < l)
        {
            // 수강 신청 인원이 수강 가능 인원보다 적으면 1점으로 무조건 가능
            pq.push(1);
        }
        else
        {
            pq.push(v[p - l]);
        }
    }

    int sum = 0;

    while (!pq.empty() && sum + pq.top() <= m)
    {
        ++ans;
        sum += pq.top();
        pq.pop();
    }
    std::cout << ans;

    // int nn;
    // std::cin >> nn;
    return 0;
}