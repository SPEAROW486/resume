
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n;
std::vector<int> v;

int get_j()
{
    int tmp = n;
    int sum = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        int count = 0;
        count = tmp / v[i];
        if (count > 0)
        {
            sum += count;
            tmp %= v[i];
        }
    }

    return tmp + sum * v.back();
}

int get_s()
{
    int tmp = n;
    int sum = 0;
    int ascending = 0;
    int descending = 0;
    for (int i = 1; i < v.size(); ++i)
    {
        if (v[i] > v[i - 1])
        {
            ++ascending;
            descending = 0;
        }
        else if (v[i] < v[i - 1])
        {
            ++descending;
            ascending = 0;
        }

        if (ascending >= 3)
        {
            tmp += v[i] * sum;
            sum = 0;
        }
        else if (descending >= 3)
        {
            int count = 0;
            count = tmp / v[i];
            if (count > 0)
            {
                sum += count;
                tmp %= v[i];
            }
        }
    }

    return tmp + sum * v.back();
}

int main()
{
    FASTIO;

    std::cin >> n;

    for (int i = 0; i < 14; ++i)
    {
        int tmp;
        std::cin >> tmp;
        v.push_back(tmp);
    }

    if (get_j() > get_s())
    {
        std::cout << "BNP\n";
    }
    else if (get_j() < get_s())
    {
        std::cout << "TIMING\n";
    }
    else
    {
        std::cout << "SAMESAME\n";
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}