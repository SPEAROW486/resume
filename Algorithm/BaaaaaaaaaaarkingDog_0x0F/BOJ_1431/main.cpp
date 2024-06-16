
#include <bits/stdc++.h>

constexpr int MAX = 51;
std::string buf[MAX];
int n;

bool pred(const std::string &lhs, const std::string &rhs)
{
    if (lhs.length() != rhs.length())
    {
        return lhs.length() < rhs.length();
    }
    else if (lhs.length() == rhs.length())
    {
        int lsum = 0;
        int rsum = 0;
        for (int i = 0; i < lhs.length(); ++i)
        {
            if (isdigit(lhs[i]))
            {
                lsum += lhs[i] - '0';
            }

            if (isdigit(rhs[i]))
            {
                rsum += rhs[i] - '0';
            }
        }

        if (lsum != rsum)
        {
            return lsum < rsum;
        }
    }
    return lhs < rhs;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> buf[i];
    }

    std::sort(buf, buf + n, pred);

    for (int i = 0; i < n; ++i)
    {
        std::cout << buf[i] << "\n";
    }

    // int nn;
    // std::cin >> n;
    return 0;
}