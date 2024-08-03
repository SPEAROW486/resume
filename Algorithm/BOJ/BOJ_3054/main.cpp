
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

std::string s;
std::vector<std::string> v;

int dx[8] = {-2, 2, 0, 0, -1, -1, 1, 1};
int dy[8] = {0, 0, -2, 2, -1, 1, -1, 1};

int main()
{
    FASTIO;

    std::cin >> s;

    for (int i = 0; i < 5; ++i)
    {
        std::string tmp(s.length() * 4 + 1, '.');
        v.push_back(tmp);
    }

    constexpr int middle = 2;
    int idx = 2;
    for (int i = 1; i <= s.size(); ++i)
    {
        v[middle][idx] = s[i - 1];

        for (int dir = 0; dir < 8; ++dir)
        {
            const char c = i % 3 == 0 ? '*' : '#';

            int nx = middle + dx[dir];
            int ny = idx + dy[dir];

            if (v[nx][ny] == '*')
            {
                continue;
            }

            v[nx][ny] = c;
        }
        idx += 4;
    }

    for (int i = 0; i < v.size(); ++i)
    {
        std::cout << v[i] << "\n";
    }

    int nn;
    std::cin >> nn;
    return 0;
}