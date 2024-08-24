
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

constexpr int BOARD_SIZE = 8;
std::string s1, s2;
int n;

std::pair<int, int> get_direction(std::string s)
{
    // x ,y
    static std::unordered_map<std::string, std::pair<int, int>> map =
        {
            {"R", {0, 1}},
            {"L", {0, -1}},
            {"B", {-1, 0}},
            {"T", {1, 0}},
            {"RT", {1, 1}},
            {"LT", {1, -1}},
            {"RB", {-1, 1}},
            {"LB", {-1, -1}}};

    return map[s];
}

std::pair<int, int> get_position(const std::string &s)
{
    return {s[1] - '0', s[0] - 'A' + 1}; // y, x
}

std::string to_position_string(const std::pair<int, int> &pos)
{
    return {static_cast<char>(pos.second + 'A' - 1), static_cast<char>(pos.first + '0')};
}

int main()
{
    // FASTIO;

    std::cin >> s1 >> s2 >> n;

    std::pair<int, int> king = get_position(s1);
    std::pair<int, int> stone = get_position(s2);

    for (int i = 0; i < n; ++i)
    {
        std::string cmd;
        std::cin >> cmd;

        auto dir = get_direction(cmd);
        auto new_king = std::make_pair(king.first + dir.first, king.second + dir.second);

        if (new_king.first < 1 || new_king.first > BOARD_SIZE ||
            new_king.second < 1 || new_king.second > BOARD_SIZE)
        {
            continue;
        }

        if (new_king == stone)
        {
            auto new_stone = std::make_pair(stone.first + dir.first, stone.second + dir.second);
            if (new_stone.first < 1 || new_stone.first > BOARD_SIZE ||
                new_stone.second < 1 || new_stone.second > BOARD_SIZE)
            {
                continue;
            }
            stone = new_stone;
        }

        king = new_king;
    }

    std::cout << to_position_string(king) << "\n"
              << to_position_string(stone) << "\n";

    int nn;
    std::cin >> nn;
    return 0;
}