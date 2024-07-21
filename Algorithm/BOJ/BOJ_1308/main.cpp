
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

bool is_leap(int year)
{
    bool leap = false;
    if (year % 400 == 0)
    {
        leap = true;
    }
    else if (year % 100 == 0)
    {
        leap = false;
    }
    else if (year % 4 == 0)
    {
        leap = true;
    }
    return leap;
}

int get_days(int year, int month, int day)
{
    int d[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int ld[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int result = 0;

    // 연도 다 더하기
    for (int i = 1; i < year; ++i)
    {
        result += is_leap(i) ? 366 : 365;
    }

    // 지나온 달 더하기
    for (int i = 1; i < month; ++i)
    {
        result += is_leap(year) ? ld[i] : d[i];
    }

    // 현재 달의 날짜 더하기
    result += day;

    return result;
}

int main()
{
    // FASTIO;
    int today_year, today_month, today_days;
    std::cin >> today_year >> today_month >> today_days;

    int next_year, next_month, next_days;
    std::cin >> next_year >> next_month >> next_days;

    int t = get_days(today_year, today_month, today_days);
    int n = get_days(next_year, next_month, next_days);

    if (next_year - today_year > 1000 || (next_year - today_year == 1000 && (next_month > today_month || (next_month == today_month && next_days >= today_days))))
    {
        std::cout << "gg\n";
    }
    else
    {
        std::cout << "D-" << n - t << "\n";
    }

    int nn;
    std::cin >> nn;
    return 0;
}