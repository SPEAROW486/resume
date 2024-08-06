
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int h, w;
std::vector<std::string> v;
std::vector<std::pair<int, int>> c;
std::vector<std::vector<int>> ans;

int main()
{
    FASTIO;
    std::cin >> h >> w;
    for (int i = 0; i < h; ++i)
    {
        std::string s;
        std::cin >> s;
        v.push_back(s);
    }

    ans.resize(h);
    for (int i = 0; i < ans.size(); ++i)
    {
        ans[i].resize(w);
        for (int j = 0; j < ans[i].size(); ++j)
        {
            if (v[i][j] == 'c')
            {
                ans[i][j] = 0;
                c.push_back({i, j});
            }
            else
            {
                ans[i][j] = -1;
            }
        }
    }

    for (int i = 0; i < c.size(); ++i)
    {
        int cx = c[i].first;
        int cy = c[i].second;
        int bias = 1;
        while (true)
        {
            int nx = cx;
            int ny = cy + bias;

            if (nx >= h || nx < 0 || ny >= w || ny < 0 || ans[nx][ny] == 0)
            {
                break;
            }

            ans[nx][ny] = ans[cx][cy] + 1;
            cx = nx;
            cy = ny;
        }
    }

    for (int i = 0; i < ans.size(); ++i)
    {
        for (int j = 0; j < ans[i].size(); ++j)
        {
            std::cout << ans[i][j] << " ";
        }
        std::cout << "\n";
    }

    int nn;
    std::cin >> nn;
    return 0;
}