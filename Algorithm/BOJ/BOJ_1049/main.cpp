
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n, m;
std::vector<int> paks;
std::vector<int> bulks;

// 처음에 비슷한 문제를 dp로 풀었던 경험이 있어서 dp로 접근했는데 막상 코드를 짜보니 좀 애매한 케이스가 있어서
// 20분 경과됬고 태그 까보니 그리디였음.
// 그래서 쭉 보니까 최선의 선택이 보임. (그렇게 어렵지 않은 그리디는 직관적으로 봤을때 어떻게 고르는게 좋을지 눈에 보이려나?, 적어도 이건 보이긴 했는디)

int main()
{
    FASTIO;

    std::cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int p, b;
        std::cin >> p >> b;

        paks.push_back(p);
        bulks.push_back(b);
    }

    std::sort(paks.begin(), paks.end());
    std::sort(bulks.begin(), bulks.end());

    const int bulk_sets = bulks[0] * 6;

    int ans = 0;
    if (bulk_sets < paks[0])
    {
        // 벌크로 6개 구매하는게 패키지 1개 구매하는거보다 싸다면?
        // 그럼 무조건 제일 싼 벌크로 n개만큼 구매.
        ans = n * bulks[0];
    }
    else
    {
        // 그게아니면 팩이랑 벌크를 혼합해서 사거나 패키지만 사거나.
        const int pak_count = n / 6;
        const int bulk_count = n % 6;
        const int pak_redundancy_count = bulk_count != 0 ? pak_count + 1 : pak_count;
        ans = std::min(paks[0] * pak_redundancy_count, paks[0] * pak_count + bulks[0] * bulk_count);
    }

    std::cout << ans;
    return 0;
}