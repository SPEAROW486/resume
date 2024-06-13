
#include <bits/stdc++.h>

int n;

constexpr int MAX = 1001;
int buf[MAX];

int main()
{
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        std::cin >> buf[i];
    }

    int max = *std::max_element(buf, buf + n);
    double sum = 0.0f;
    for (int i = 0; i < n; ++i)
    {
        double temp = (double)buf[i] / (double)max * 100.0f;
        sum += temp;
    }

    std::cout << (double)(sum / n);
    int nn;
    std::cin >> nn;

    return 0;
}