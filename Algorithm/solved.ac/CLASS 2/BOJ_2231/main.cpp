
#include <bits/stdc++.h>

int n;
constexpr int MAX = 1000001;
int buf[MAX];

int main()
{
    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        buf[i] = i + 1;
    }

    std::vector<int> v;
    int i = 0;
    while (i < n)
    {
        int mid_value = buf[i];
        std::string mid_string = std::to_string(mid_value);
        for (int j = 0; j < mid_string.length(); ++j)
        {
            int temp = mid_string[j] - '0';
            mid_value += temp;
        }

        if (mid_value == n)
        {
            v.push_back(buf[i]);
        }
        ++i;
    }

    std::sort(v.begin(), v.end());

    int result = v.size() > 0 ? v[0] : 0;
    std::cout << result;

    return 0;
}