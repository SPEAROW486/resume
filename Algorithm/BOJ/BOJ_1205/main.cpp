
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n, s, p;
std::vector<int> v;

int main()
{
    //    FASTIO;

    std::cin >> n >> s >> p;

    for (int i = 0; i < n; ++i)
    {
        int tmp;
        std::cin >> tmp;
        v.push_back(tmp);
    }

    // 새로운 점수가 몇 등인지 계산
    int rank = 1;  // 1등부터 시작
    int count = 0; // 리스트에 들어갈 수 있는 점수 개수 카운트

    for (int i = 0; i < n; ++i)
    {
        if (v[i] > s)
        {
            rank++;
        }
        else if (v[i] == s)
        {
            rank = rank; // 같은 점수일 경우 등수는 변하지 않음
        }
        else
        {
            break; // 새로운 점수가 더 크다면 그 이후의 점수는 비교하지 않음
        }
        count++;
    }

    // P가 꽉 차고, 새로운 점수가 들어갈 자리가 없는 경우
    if (count == p && v[n - 1] >= s)
    {
        std::cout << -1 << std::endl;
    }
    else
    {
        std::cout << rank << std::endl;
    }

    int nn;
    std::cin >> nn;
    return 0;
}