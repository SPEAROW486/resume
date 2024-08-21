
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n, m;
std::vector<std::string> v;

bool check(const std::vector<std::string> &b, int ex, int ey)
{
    for (int x = 0; x < 4; ++x)
    {
        for (int y = 0; y < 4; ++y)
        {
            int nx = ex + x;
            int ny = ey + y;

            if (b[x][y] != v[nx][ny])
            {
                return false;
            }
        }
    }
    return true;
}

void solve(const std::vector<std::pair<int, int>> &vec)
{
    std::vector<std::string> t1 =
        {
            "....",
            "....",
            "....",
            "...."};

    std::vector<std::string> t2 =
        {
            "****",
            "....",
            "....",
            "...."};

    std::vector<std::string> t3 =
        {
            "****",
            "****",
            "....",
            "...."};

    std::vector<std::string> t4 =
        {
            "****",
            "****",
            "****",
            "...."};

    std::vector<std::string> t5 =
        {
            "****",
            "****",
            "****",
            "****"};

    std::vector<std::vector<std::string>> blindes = {t1, t2, t3, t4, t5};
    std::vector<int> ans = {0, 0, 0, 0, 0};
    for (int i = 0; i < vec.size(); ++i)
    {
        int ex = vec[i].first;
        int ey = vec[i].second;

        // ex, ey를 기준으로 4,4 그리드를 체크
        // v[i][j] == tX랑 같은지
        // OOB 체크를 해야할까? 안해도될거 같은데
        for (int j = 0; j < blindes.size(); ++j)
        {
            if (check(blindes[j], ex, ey))
            {
                ++ans[j];
            }
        }
    }

    for (int i = 0; i < ans.size(); ++i)
    {
        std::cout << ans[i] << " ";
    }
}

int main()
{
    FASTIO;

    std::cin >> m >> n;
    for (int i = 0; i < 5 * m + 1; ++i)
    {
        std::string s;
        std::cin >> s;
        v.push_back(s);
    }

    // 층수가 m
    // 첫번째 창문의 엔트리 포인트는 1,1

    // m이 1일땐 1
    // m이 2일댄 6

    // n이 1일땐 1
    // n이 2일땐 6

    // 1 + 5*(m-1)이고 x축은
    // 1 + 5*(n-1)이 y축이네

    // m,n값을 기준으로 각 창문의 위치를 베이크 해야할듯

    std::vector<std::pair<int, int>> entries;
    for (int x = 1; x <= 1 + 5 * (m - 1); x += 5)
    {
        for (int y = 1; y <= 1 + 5 * (n - 1); y += 5)
        {
            entries.push_back({x, y});
        }
    }

    solve(entries);

    // int nn;
    // std::cin >> nn;
    return 0;
}