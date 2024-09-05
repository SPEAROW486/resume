
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n;
std::vector<std::pair<int, int>> v;

int solve(int cnt)
{
    // cnt만큼 조합을 뽑아서 최솟값 계산 후 리턴 해줄것임.

    // 신맛은 곱 (first)
    // 쓴맛은 합 (second)
    int result = 1e9;

    std::vector<bool> selected(n, true);
    for (int i = 0; i < cnt; ++i)
    {
        selected[i] = false;
    }

    do
    {
        int t1 = 1;
        int t2 = 0;
        for (int i = 0; i < v.size(); ++i)
        {
            if (!selected[i])
            {
                t1 *= v[i].first;
                t2 += v[i].second;
            }
        }

        result = std::min(result, abs(t1 - t2));
    } while (std::next_permutation(selected.begin(), selected.end()));

    return result;
}

int main()
{
    FASTIO;

    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int d1, d2;
        std::cin >> d1 >> d2;
        v.push_back({d1, d2});
    }

    // 신맛, 쓴맛이 작은 순서대로 정렬
    std::sort(v.begin(), v.end());
    // 1개부터 n개까지 뽑기
    int min = 1e9;
    for (int i = 1; i <= n; ++i)
    {
        min = std::min(min, solve(i));
    }

    std::cout << min;

    // int nn;
    // std::cin >> nn;
    return 0;
}