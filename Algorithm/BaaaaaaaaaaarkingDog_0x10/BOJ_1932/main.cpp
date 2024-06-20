
#include <bits/stdc++.h>

int n;
constexpr int MAX = 501;
int d[MAX][MAX];

// 이 문제에 대해서 테이블과 풀이가 생각이 안났던 가장 큰 이유는
// N을 고려하지않고 N^2풀이를 생각하지않았기 때문
// N의 사이즈부터 고려해서 시간복잡도 계산하고 그 시간복잡도 안에서 할수있는 풀이부터 생각해보는거로
// N이 500이고 시간제한이 2초니까 N^3 풀이를 해도 1억2천만번 정도 연산이므로 가능했을지도

// 테이블 = d[i][j] = i번째 줄의 j 번째 수까지 더 했을때의 최대값

// 점화식 = d[1][1] = 7;
//         d[2][1] = d[1][1] + s[2][1];
//         d[2][2] = d[1][1] + s[2][2];

int main()
{
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(NULL);

    std::cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            std::cin >> d[i][j];
        }
    }

    if (n == 1)
    {
        std::cout << d[1][1];
        return 0;
    }

    // 입력된 값을 그대로 쓸거니까 초기값은 따로 없고
    //
    int max = INT_MIN;
    for (int i = 2; i <= n; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            // 양 끝단이면 좌우 선택이 없고 한쪽만
            if (j == 1)
            {
                d[i][j] += d[i - 1][j];
            }
            else if (j == i)
            {
                d[i][j] += d[i - 1][j - 1];
            }
            else
            {
                d[i][j] += std::max(d[i - 1][j], d[i - 1][j - 1]);
            }
            max = std::max(max, d[i][j]);
        }
    }

    std::cout << max;

    // int nn;
    // std::cin >> nn;
    return 0;
}