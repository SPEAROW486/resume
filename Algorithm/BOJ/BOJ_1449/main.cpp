
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n, l;
std::vector<int> vec;

int main()
{
    FASTIO;
    std::cin >> n >> l;
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        std::cin >> tmp;
        vec.push_back(tmp);
    }
    std::sort(vec.begin(), vec.end());

    int start = vec[0];

    int tape = 0;
    for (int i = 1; i < vec.size(); ++i)
    {
        if (l <= vec[i] - start)
        {
            ++tape;
            start = vec[i];
        }
    }

    std::cout << tape + 1;

    // int nn;
    // std::cin >> nn;
    return 0;
}