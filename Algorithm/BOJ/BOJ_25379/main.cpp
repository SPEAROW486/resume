
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n;
std::vector<int> v;

int main()
{
    // FASTIO;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        std::cin >> tmp;
        v.push_back(tmp);
    }

    long long odd = 0;
    long long even = 0;

    long long odd_count = 0;
    long long even_count = 0;

    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i] % 2 == 0)
        {
            ++even;
            odd_count += odd;
        }
        else
        {
            ++odd;
            even_count += even;
        }
    }

    std::cout << std::min(odd_count, even_count);

    int nn;
    std::cin >> nn;
    return 0;
}