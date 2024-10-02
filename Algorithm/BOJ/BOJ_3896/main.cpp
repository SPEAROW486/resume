#include <bits/stdc++.h>
#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 3896

// 최대 소수 범위
constexpr int MAX_NUM = 1299709;

// 에라토스테네스의 체를 이용해 소수를 판별하고, 소수 리스트를 반환하는 함수
std::vector<int> sieve(int max_num)
{
    std::vector<int> primes;
    std::vector<bool> is_prime(max_num + 1, true);
    is_prime[0] = is_prime[1] = false;

    // 에라토스테네스의 체 알고리즘
    for (int i = 2; i * i <= max_num; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= max_num; j += i)
            {
                is_prime[j] = false;
            }
        }
    }

    // 소수만을 추출하여 primes 벡터에 저장
    for (int i = 2; i <= max_num; i++)
    {
        if (is_prime[i])
        {
            primes.push_back(i);
        }
    }

    return primes;
}

int main()
{
    FASTIO;

    int t;
    std::cin >> t; // 테스트 케이스 개수 입력

    // 미리 소수 리스트를 구함
    std::vector<int> primes = sieve(MAX_NUM);

    // 각 입력값에 대해 처리
    while (t--)
    {
        int k;
        std::cin >> k; // k값 입력

        // k가 소수인 경우 0 출력
        if (std::binary_search(primes.begin(), primes.end(), k))
        {
            std::cout << "0\n";
            continue;
        }

        // k보다 작은 가장 큰 소수 찾기
        int idx = std::lower_bound(primes.begin(), primes.end(), k) - primes.begin();
        int lower_prime = primes[idx - 1];
        int upper_prime = primes[idx];

        // 두 소수의 차이 출력
        std::cout << upper_prime - lower_prime << "\n";
    }

    return 0;
}
