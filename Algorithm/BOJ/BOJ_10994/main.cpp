
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n;
std::vector<std::string> v;

void draw(int len, int row, int col)
{
    for (int i = 0; i < len; ++i)
    {
        if (i == 0 || i == len - 1)
        {
            for (int j = 0; j < len; ++j)
            {
                v[row + i][col + j] = '*';
            }
        }
        else
        {
            v[row + i][col] = '*';
            v[row + i][col + len - 1] = '*';
        }
    }
}

void solve(int depth, int row, int col)
{
    int len = 4 * depth - 3;
    draw(len, row, col);

    if (depth == 1)
    {
        return;
    }

    solve(depth - 1, row + 2, col + 2);
}

int main()
{
    FASTIO;

    std::cin >> n;

    for (int i = 0; i < 4 * n - 3; ++i)
    {
        std::string s;
        s.resize(4 * n - 3);
        for (int j = 0; j < s.length(); ++j)
        {
            s[j] = ' ';
        }
        v.push_back(s);
    }

    solve(n, 0, 0);
    for (int i = 0; i < v.size(); ++i)
    {
        std::cout << v[i] << "\n";
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}