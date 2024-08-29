
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

constexpr int MOD = 1000000007;
constexpr int MAX = 51; // n+2항이니까 52항까지 있어야함.
int calls[MAX];
int n;

int main()
{
    FASTIO;
    std::cin >> n;
    calls[0] = 1;
    calls[1] = 1;

    for (int i = 2; i < MAX; ++i)
    {
        calls[i] = calls[i - 1] + calls[i - 2] + 1;
        calls[i] %= MOD;
    }

    std::cout << calls[n];

    // int nn;
    // std::cin >> nn;
    return 0;
}
