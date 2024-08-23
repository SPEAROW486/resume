
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n, k;
std::vector<int> v;

// 왼손
char s_l[] = {'q', 'w', 'e', 'r', 't',
              'a', 's', 'd', 'f', 'g',
              'z', 'x', 'c', 'v'};
int s_l_p[][2] = {{0, 0}, {0, 1}, {0, 2}, {0, 3}, {0, 4}, {1, 0}, {1, 1}, {1, 2}, {1, 3}, {1, 4}, {2, 0}, {2, 1}, {2, 2}, {2, 3}};

// 오른손
char s_r[] = {
    'y',
    'u',
    'i',
    'o',
    'p',
    'h',
    'j',
    'k',
    'l',
    'b',
    'n',
    'm',
};
int s_r_p[][2] = {{0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {1, 1}, {1, 2}, {1, 3}, {1, 4}, {2, 0}, {2, 1}, {2, 2}};

char l, r;
std::string str;
int l_postion[2] = {0}; // 시작위치
int r_postion[2] = {0};

int main()
{
    // FASTIO;
    std::cin >> l >> r;
    std::cin >> str;

    for (int i = 0; i < 14; ++i)
    {
        if (l == s_l[i])
        {
            l_postion[0] = s_l_p[i][0];
            l_postion[1] = s_l_p[i][1];
        }
    }

    for (int i = 0; i < 12; ++i)
    {
        if (r == s_r[i])
        {
            r_postion[0] = s_r_p[i][0];
            r_postion[1] = s_r_p[i][1];
        }
    }

    int time = 0;
    for (int i = 0; i < str.size(); ++i)
    {
        for (int j = 0; j < 14; ++j)
        {
            if (str[i] == s_l[j])
            {
                time += abs(l_postion[0] - s_l_p[j][0]) + abs(l_postion[1] - s_l_p[j][1]) + 1;
                l_postion[0] = s_l_p[j][0];
                l_postion[1] = s_l_p[j][1];
            }
        }

        for (int j = 0; j < 12; ++j)
        {
            if (str[i] == s_r[j])
            {
                time += abs(r_postion[0] - s_r_p[j][0]) + abs(r_postion[1] - s_r_p[j][1]) + 1;
                r_postion[0] = s_r_p[j][0];
                r_postion[1] = s_r_p[j][1];
            }
        }
    }

    std::cout << time;

    int nn;
    std::cin >> nn;
    return 0;
}