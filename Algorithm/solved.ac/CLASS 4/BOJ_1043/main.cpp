
#include <bits/stdc++.h>

constexpr int MAX = 51;
int n, m;
int knows_count;

std::vector<int> parent(MAX);
std::vector<int> knows(MAX);

int find_parent(std::vector<int> &v, int x)
{
    if (v[x] == x)
    {
        return x;
    }
    return v[x] = find_parent(v, v[x]);
}

void union_sets(std::vector<int> &v, int a, int b)
{
    int x = find_parent(v, a);
    int y = find_parent(v, b);

    if (x != y)
    {
        v[y] = x;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m;
    std::cin >> knows_count;
    for (int i = 0; i < knows_count; ++i)
    {
        std::cin >> knows[i];
    }

    for (int i = 1; i <= n; ++i)
    {
        parent[i] = i;
    }

    std::vector<std::vector<int>> parties(m);
    for (int i = 0; i < m; ++i)
    {
        int party_length;
        std::cin >> party_length;

        parties[i].resize(party_length);
        for (int j = 0; j < party_length; ++j)
        {
            std::cin >> parties[i][j];
        }

        // 파티에 참석한 사람들을 맨앞사람을 기준으로 같은 그룹으로 배정
        for (int k = 0; k < party_length - 1; ++k)
        {
            union_sets(parent, parties[i][k], parties[i][k + 1]);
        }
    }

    // 진실을 아는 사람들을 같은 그룹으로 배정
    for (int i = 0; i < knows_count - 1; ++i)
    {
        union_sets(parent, knows[i], knows[i + 1]);
    }

    // 진실 그룹의 대표자
    int representative = knows_count != 0 ? find_parent(parent, knows[0]) : -1;

    int ans = 0;
    for (auto &elem : parties)
    {
        bool can_lie = true;
        for (int i = 0; i < elem.size(); ++i)
        {
            // 각 참석자들이 진실 그룹인지
            if (find_parent(parent, elem[i]) == representative)
            {
                can_lie = false;
                break;
            }
        }

        if (can_lie)
        {
            ++ans;
        }
    }

    std::cout << ans;

    // int nn;
    // std::cin >> nn;
    return 0;
}