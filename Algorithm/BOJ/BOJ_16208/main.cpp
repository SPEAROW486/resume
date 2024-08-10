
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

long long n;
long long sum;
long long ans;
std::vector<int> v;

int main()
{
    FASTIO;

    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        std::cin >> tmp;
        v.push_back(tmp);
        sum += tmp;
    }

    std::sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); ++i)
    {
        ans += (v[i] * (sum - v[i]));
        sum -= v[i];
    }

    std::cout << ans << "\n";

    // int nn;
    // std::cin >> nn;
    return 0;
}