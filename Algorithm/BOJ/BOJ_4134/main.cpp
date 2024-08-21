
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int tc;
bool is_primenumber(long long n)
{
    if (n <= 1)
    {
        return false;
    }

    for (long long i = 2; i <= sqrt(n); ++i)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    FASTIO;
    std::cin >> tc;
    while (tc--)
    {
        long long n;
        std::cin >> n;

        // n보다 크거나 같은 가장 작은 소수찾기.
        long long tmp = n;
        while (true)
        {
            if (is_primenumber(tmp))
            {
                std::cout << tmp << "\n";
                break;
            }
            else
            {
                ++tmp;
            }
        }
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}