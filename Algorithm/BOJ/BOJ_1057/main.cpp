
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n, kim, im;
int main()
{
    FASTIO;
    std::cin >> n >> kim >> im;

    int round = 0;
    while (kim != im)
    {
        kim = (kim + 1) / 2;
        im = (im + 1) / 2;
        ++round;
    }

    std::cout << round;

    return 0;
}