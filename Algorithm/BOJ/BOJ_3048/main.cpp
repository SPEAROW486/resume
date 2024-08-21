
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n1, n2;
std::string s1;
std::string s2;
int t;

std::vector<bool> direction;

int main()
{
    FASTIO;
    std::cin >> n1 >> n2;
    std::cin >> s1 >> s2;
    std::cin >> t;

    direction.resize(s1.length() + s2.length());
    std::fill(direction.begin(), direction.begin() + s1.length(), true);

    std::reverse(s1.begin(), s1.end());
    std::string s3 = s1 + s2;
    int time = 0;
    while (time != t)
    {
        for (int i = 0; i < direction.size() - 1; ++i)
        {
            if (direction[i] && !direction[i + 1])
            {
                std::swap(direction[i], direction[i + 1]);
                std::swap(s3[i], s3[i + 1]);
                ++i;
            }
        }
        ++time;
    }

    std::cout << s3 << "\n";

    // int nn;
    // std::cin >> nn;
    return 0;
}