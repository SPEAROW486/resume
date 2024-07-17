
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

constexpr int MAX = 51;

std::vector<std::pair<int, int>> vec;
int p[MAX];
int n;

int main()
{
    FASTIO;

    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int num;
        std::cin >> num;

        vec.push_back({num, i});
    }

    // A 를 오름차순으로 정렬해서 B를 만들었을때
    // A의 원소가 B에 어디에 위치해있는가를 또 하나의 수열로 보는 문제

    std::vector<std::pair<int, int>> b(vec.begin(), vec.end());
    std::sort(b.begin(), b.end());

    for (int i = 0; i < vec.size(); ++i)
    {
        for (int j = 0; j < b.size(); ++j)
        {
            if (vec[i].second == b[j].second)
            {
                std::cout << j << " ";
            }
        }
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}