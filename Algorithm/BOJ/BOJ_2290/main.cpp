#include <bits/stdc++.h>
#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// 이걸 아래 벡터로 표현함.
//  --      a
// |  |     f   b
//  --      g
// |  |     e   c
//  --      d

const std::vector<std::vector<int>> segments = {
    {1, 1, 1, 0, 1, 1, 1}, // 0
    {0, 0, 1, 0, 0, 1, 0}, // 1
    {1, 0, 1, 1, 1, 0, 1}, // 2
    {1, 0, 1, 1, 0, 1, 1}, // 3
    {0, 1, 1, 1, 0, 1, 0}, // 4
    {1, 1, 0, 1, 0, 1, 1}, // 5
    {1, 1, 0, 1, 1, 1, 1}, // 6
    {1, 0, 1, 0, 0, 1, 0}, // 7
    {1, 1, 1, 1, 1, 1, 1}, // 8
    {1, 1, 1, 1, 0, 1, 1}  // 9
};

void printRow(int num, int s, int part)
{
    if (part == 0 || part == 3 || part == 6)
    {
        std::cout << " ";
        if (segments[num][part] == 1)
        {
            for (int i = 0; i < s; ++i)
            {
                std::cout << "-";
            }
        }
        else
        {
            for (int i = 0; i < s; ++i)
            {
                std::cout << " ";
            }
        }
        std::cout << " ";
    }
}

void printColumn(int num, int s, int part1, int part2)
{
    if (segments[num][part1] == 1)
    {
        std::cout << "|";
    }
    else
    {
        std::cout << " ";
    }
    for (int i = 0; i < s; ++i)
    {
        std::cout << " ";
    }
    if (segments[num][part2] == 1)
    {
        std::cout << "|";
    }
    else
    {
        std::cout << " ";
    }
}

int main()
{
    // FASTIO;

    int s;
    std::string n;
    std::cin >> s >> n;
    int len = n.length();

    for (int i = 0; i < len; ++i)
    {
        if (i != 0)
        {
            std::cout << " ";
        }
        printRow(n[i] - '0', s, 0);
    }
    std::cout << "\n";

    for (int row = 0; row < s; ++row)
    {
        for (int i = 0; i < len; ++i)
        {
            if (i != 0)
            {
                std::cout << " ";
            }
            printColumn(n[i] - '0', s, 1, 2);
        }
        std::cout << "\n";
    }

    for (int i = 0; i < len; ++i)
    {
        if (i != 0)
        {
            std::cout << " ";
        }
        printRow(n[i] - '0', s, 3);
    }
    std::cout << "\n";

    for (int row = 0; row < s; ++row)
    {
        for (int i = 0; i < len; ++i)
        {
            if (i != 0)
            {
                std::cout << " ";
            }
            printColumn(n[i] - '0', s, 4, 5);
        }
        std::cout << "\n";
    }
    for (int i = 0; i < len; ++i)
    {
        if (i != 0)
        {
            std::cout << " ";
        }
        printRow(n[i] - '0', s, 6);
    }
    std::cout << "\n";

    int nn;
    std::cin >> nn;

    return 0;
}
