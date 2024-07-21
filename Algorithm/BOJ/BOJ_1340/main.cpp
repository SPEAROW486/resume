
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

std::string s;

bool is_leap_year(int y)
{
    if (y % 400 == 0)
    {
        return true;
    }
    else if (y % 100 == 0)
    {
        return false;
    }
    else if (y % 4 == 0)
    {
        return true;
    }
    return false;
}

int get_elapsed_days(int y, int month)
{
    int days = 0;
    int cal[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int leap_cal[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    bool leap = is_leap_year(y);
    for (int i = 1; i < month; ++i)
    {
        days += leap ? leap_cal[i] : cal[i];
    }
    return days;
}

int main()
{
    FASTIO;
    std::getline(std::cin, s);

    int idx = s.find(",");
    std::string part1 = s.substr(0, idx);
    std::string part2 = s.substr(idx + 2);
    idx = part1.find(" ");

    std::string mm = part1.substr(0, idx);
    std::string dd = part1.substr(idx + 1);
    std::string months[13] = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    int m = 0;
    for (int i = 1; i < 13; ++i)
    {
        if (mm == months[i])
        {
            m = i;
            break;
        }
    }
    int d = std::stoi(dd);

    idx = part2.find(":");
    std::string hh = part2.substr(idx - 2, 2);
    std::string minute_str = part2.substr(idx + 1, 2);

    int h = std::stoi(hh);
    int minute = std::stoi(minute_str);

    int elapsed_second = 0;
    elapsed_second += minute * 60;
    elapsed_second += h * 3600;

    std::string year = part2.substr(0, 4);

    int elap_days = get_elapsed_days(std::stoi(year), m) + d - 1;
    elapsed_second += elap_days * 24 * 3600;

    int days = is_leap_year(std::stoi(year)) ? 366 : 365;
    int total_second = days * 24 * 3600;

    double ans = ((double)elapsed_second / (double)total_second) * 100;

    std::cout << std::fixed;
    std::cout.precision(9);
    std::cout << ans;

    // int nn;
    // std::cin >> nn;
    return 0;
}