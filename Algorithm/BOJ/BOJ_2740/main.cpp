
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

std::vector<std::vector<int>> matrix_a;
std::vector<std::vector<int>> matrix_b;
int n, m, k;

void dump(const std::vector<std::vector<int>> &v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        for (int j = 0; j < v[i].size(); ++j)
        {
            std::cout << v[i][j] << " ";
        }
        std::cout << "\n";
    }
}

std::vector<std::vector<int>> matrix_multifly(const std::vector<std::vector<int>> &v1, const std::vector<std::vector<int>> &v2)
{
    std::vector<std::vector<int>> result;
    result.resize(n);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < k; ++j)
        {
            int tmp = 0;
            for (int kk = 0; kk < m; ++kk)
            {
                tmp += v1[i][kk] * v2[kk][j];
            }
            result[i].push_back(tmp);
        }
    }

    return result;
}

int main()
{
    FASTIO;

    std::cin >> n >> m;

    matrix_a.resize(n);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            int tmp;
            std::cin >> tmp;
            matrix_a[i].push_back(tmp);
        }
    }

    std::cin >> m >> k;

    matrix_b.resize(m);
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < k; ++j)
        {
            int tmp;
            std::cin >> tmp;
            matrix_b[i].push_back(tmp);
        }
    }

    dump(matrix_multifly(matrix_a, matrix_b));

    int nn;
    std::cin >> nn;
    return 0;
}