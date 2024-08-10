
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

std::string a;
std::string b;
int alphabet[26] = {3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};

int main()
{
    FASTIO;
    std::cin >> a >> b;

    std::vector<int> c;
    for (int i = 0; i < a.length(); ++i)
    {
        c.push_back(alphabet[a[i] - 'A']);
        c.push_back(alphabet[b[i] - 'A']);
    }

    while (c.size() > 2)
    {
        std::vector<int> tmp;
        for (int i = 1; i < c.size(); ++i)
        {
            tmp.push_back((c[i - 1] + c[i]) % 10);
        }
        c = std::move(tmp);
    }

    std::cout << std::to_string(c[0]) << std::to_string(c[1]) << "\n";

    // int nn;
    // std::cin >> nn;
    return 0;
}