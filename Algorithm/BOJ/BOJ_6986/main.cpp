
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n, k;

double get_trimmed_mean(const std::vector<double> &v)
{
    // 양쪽에서 k개를 제거하고 남은 n개로만 평균 구하는것
    double tmp = 0;
    for (int i = k; i < v.size() - k; ++i)
    {
        tmp += v[i];
    }

    return tmp / (v.size() - 2 * k) + 1e-13;
}

double get_adjusted_mean(const std::vector<double> &v)
{
    double left = v[k];
    double right = v[v.size() - k - 1];

    double tmp = 0;
    for (int i = 0; i < k; ++i)
    {
        tmp += left;
    }

    for (int i = k; i < v.size() - k; ++i)
    {
        tmp += v[i];
    }

    for (int i = v.size() - k; i < v.size(); ++i)
    {
        tmp += right;
    }

    return tmp / v.size() + 1e-13;
}

int main()
{
    FASTIO;
    std::cin >> n >> k;
    std::vector<double> scores;
    for (int i = 0; i < n; ++i)
    {
        double tmp;
        std::cin >> tmp;
        scores.push_back(tmp);
    }

    // 정밀도 때문에 92%에서 틀려서 적절한 보정값을 더해줌.
    std::sort(scores.begin(), scores.end());
    std::cout << std::fixed << std::setprecision(2);

    std::cout << get_trimmed_mean(scores) << "\n";
    std::cout << get_adjusted_mean(scores) << "\n";

    // int nn;
    // std::cin >> nn;
    return 0;
}