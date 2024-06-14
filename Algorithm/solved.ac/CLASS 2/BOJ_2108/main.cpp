
#include <bits/stdc++.h>

int n;
constexpr int MAX = 500001;

int buf[MAX];
std::unordered_map<int, int> frequency;

int main()
{
    int n;
    std::cin >> n;

    double sum = 0;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> buf[i];
        sum += buf[i];
        frequency[buf[i]]++;
    }

    std::sort(buf, buf + n);
    int avg = std::round(sum / n);

    std::cout << avg << "\n";
    std::cout << buf[n / 2] << "\n";

    int max = 0;
    for (const auto &elem : frequency)
    {
        max = std::max(elem.second, max);
    }

    std::vector<int> candidates;
    for (const auto &elem : frequency)
    {
        if (elem.second == max)
        {
            candidates.push_back(elem.first);
        }
    }

    std::sort(candidates.begin(), candidates.end());

    int reulst = candidates.size() == 1 ? candidates[0] : candidates[1];
    std::cout << reulst << "\n";

    std::cout << buf[n - 1] - buf[0] << "\n";

    int nn;
    std::cin >> nn;

    return 0;
}