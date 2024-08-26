
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)
constexpr int MAX = 10000;
bool board[10000];

int get_watch_num(int a, int b, int c, int d)
{
    int num1 = a * 1000 + b * 100 + c * 10 + d;
    int num2 = b * 1000 + c * 100 + d * 10 + a;
    int num3 = c * 1000 + d * 100 + a * 10 + b;
    int num4 = d * 1000 + a * 100 + b * 10 + c;
    return std::min({num1, num2, num3, num4});
}

void check_watch_numbers()
{
    std::vector<int> v;
    for (int i = 1; i <= 9; ++i)
    {
        for (int j = 1; j <= 9; ++j)
        {
            for (int k = 1; k <= 9; ++k)
            {
                for (int l = 1; l <= 9; ++l)
                {
                    int number = get_watch_num(i, j, k, l);
                    board[number] = true;
                }
            }
        }
    }
}

int main()
{
    FASTIO;
    int n1, n2, n3, n4;

    std::cin >> n1 >> n2 >> n3 >> n4;
    int tmp = get_watch_num(n1, n2, n3, n4);

    int ans = 0;
    check_watch_numbers();
    for (int i = 1111; i <= tmp; ++i)
    {
        if (board[i])
        {
            ++ans;
        }
    }
    std::cout << ans;

    // int nn;
    // std::cin >> nn;
    return 0;
}