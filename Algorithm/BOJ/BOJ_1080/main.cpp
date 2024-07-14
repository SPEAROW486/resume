
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// 왜 커밋안됨?
constexpr int MAX = 51;
int a[MAX][MAX];
int b[MAX][MAX];
int n, m;

void dump()
{
    std::cout << "dump\n\n";
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            std::cout << a[i][j] << " ";
        }
        std::cout << "\n";
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            std::cout << b[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int main()
{
    FASTIO;
    std::cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        std::string s;
        std::cin >> s;
        for (int j = 0; j < m; ++j)
        {
            a[i][j] = s[j] - '0';
        }
    }

    for (int i = 0; i < n; ++i)
    {
        std::string s;
        std::cin >> s;
        for (int j = 0; j < m; ++j)
        {
            b[i][j] = s[j] - '0';
        }
    }

    // 3x3씩 뒤집음
    int count = 0;
    for (int i = 0; i < n - 2; ++i)
    {
        for (int j = 0; j < m - 2; ++j)
        {
            if (a[i][j] != b[i][j])
            {
                for (int k = i; k <= i + 2; ++k)
                {
                    for (int l = j; l <= j + 2; ++l)
                    {
                        a[k][l] = !a[k][l];
                    }
                }
                ++count;
            }
        }
    }

    // 비교해서 다른게 있으면 못바꾼거
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (a[i][j] != b[i][j])
            {
                std::cout << "-1\n";
                return 0;
            }
        }
    }

    std::cout << count << "\n";

    return 0;
}