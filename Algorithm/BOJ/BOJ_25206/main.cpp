
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

double getGradePoint(const std::string &grade)
{
    std::unordered_map<std::string, double> gradeMap = {
        {"A+", 4.5},
        {"A0", 4.0},
        {"B+", 3.5},
        {"B0", 3.0},
        {"C+", 2.5},
        {"C0", 2.0},
        {"D+", 1.5},
        {"D0", 1.0},
        {"F", 0.0}};

    return gradeMap[grade];
}

std::vector<int> v;
int main()
{
    FASTIO;
    double sum1 = 0; // 전공머시기
    double sum2 = 0; // 학점 총합
    for (int i = 0; i < 20; ++i)
    {
        std::string s;
        double score;
        std::string grade;

        std::cin >> s >> score >> grade;

        if (grade != "P")
        {
            sum1 += score * getGradePoint(grade);
            sum2 += score;
        }
    }

    std::cout << sum1 / sum2;

    // int nn;
    // std::cin >> nn;
    return 0;
}