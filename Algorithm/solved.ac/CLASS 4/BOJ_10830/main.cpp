
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

constexpr int MOD = 1000;
constexpr int MAX = 5;

int n;
long long b;
int matrix[MAX][MAX];
int ans[MAX][MAX];

void multiply(int a[MAX][MAX], int b[MAX][MAX], int out[MAX][MAX])
{
    int result[MAX][MAX];
    memset(result, 0, sizeof(result));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            for (int k = 0; k < n; ++k)
            {
                result[i][j] = (result[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    memcpy(out, result, sizeof(result));
}

void matrix_pow()
{
    int result[MAX][MAX];
    memset(result, 0, sizeof(result));
    for (int i = 0; i < n; ++i)
    {
        result[i][i] = 1; // 처음엔 단위행렬로 초기화
    }

    long long p = b;
    // 조건 아직 명확치 않음
    while (p > 0)
    {
        if (p % 2 == 1)
        {
            // 홀수
            // 처음에 홀수면 단위행렬에 매트릭스를 곱해서 matrix의 1제곱 형태로 만들고
            // 그 이후부턴 계속 짝수 연산을 하다가
            // 마지막에 홀수를 한번 더 곱해줌.
            multiply(matrix, result, result);
        }
        multiply(matrix, matrix, matrix);
        p /= 2;
    }

    memcpy(ans, result, sizeof(result));
}

int main()
{
    FASTIO;

    std::cin >> n >> b;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            std::cin >> matrix[i][j];
        }
    }

    matrix_pow();

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            std::cout << ans[i][j] << " ";
        }
        std::cout << "\n";
    }

    // int nn;
    // std::cin >> nn;

    return 0;
}