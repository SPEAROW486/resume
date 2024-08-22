
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int tc;

// k가 작기 때문에 브루트포스로 해결할 수 있을거 같은데
// 최대 1000이니까 1000 이하의 소수를 전부 구한다고치면
std::vector<int> get_prime_numbers()
{
    std::vector<int> ret;
    int k = 1000;

    std::vector<bool> prime(k + 1);
    for (int i = 2; i < k + 1; ++i)
    {
        prime[i] = true;
    }

    for (int i = 2; i * i <= k; ++i)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= k; j += i)
            {
                prime[j] = false;
            }
        }
    }

    for (int i = 2; i <= k; ++i)
    {
        if (prime[i])
        {
            ret.push_back(i);
        }
    }

    return ret;
}

std::vector<int> solve(int n, const std::vector<int> &prime)
{
    std::vector<int> ret;

    // n이 3개의 소수들의 합으로 나뉘어진다는건
    // 3개의 소수는 반드시 n보다 작다는거임.

    // n은 1000보다 작음.
    // 브루트포스인가?

    // 25의 경우 예제 출력과 다르지만 문제에서 여러 케이스가 가능하다면 그 중 하나만 출력해도 되기때문에 AC 처리
    for (int i = 0; i < prime.size(); ++i)
    {
        if (prime[i] > n)
        {
            break;
        }

        for (int j = 0; j < prime.size(); ++j)
        {
            if (prime[i] + prime[j] > n)
            {
                break;
            }

            for (int k = 0; k < prime.size(); ++k)
            {
                if (prime[i] + prime[j] + prime[k] > n)
                {
                    break;
                }

                if (prime[i] + prime[j] + prime[k] == n)
                {
                    ret.push_back(prime[i]);
                    ret.push_back(prime[j]);
                    ret.push_back(prime[k]);
                    std::sort(ret.begin(), ret.end());
                    return ret;
                }
            }
        }
    }

    return ret;
}

int main()
{
    // FASTIO;

    std::vector<int> prime = get_prime_numbers();
    std::cin >> tc;
    while (tc--)
    {
        int n;
        std::cin >> n;
        std::vector<int> ans = solve(n, prime);
        if (ans.size() > 0)
        {
            for (int i = 0; i < ans.size(); ++i)
            {
                std::cout << ans[i] << " ";
            }

            std::cout << "\n";
        }
        else
        {
            std::cout << "0\n";
        }
    }

    int nn;
    std::cin >> nn;
    return 0;
}