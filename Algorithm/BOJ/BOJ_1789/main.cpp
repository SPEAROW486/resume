
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

unsigned int s;

int main()
{
    FASTIO;
    std::cin >> s;

    // 서로 다른 N개의 자연수를 더해서 S가 될때 자연수 N의 최댓값

    // 더해서 최대개수가되려면 당연히 작은 수부터 더해야 하고
    // 그렇다면 1부터 n까지 더하는데
    // 그 합이 S가 될때가 없음.. S[19]를 구하면 190임

    // 1부터 19까지 더하면 190
    // 1부터 20까지 더하면 210이므로

    // {1~19}를 마지막항만 29로 바꾼다고 가정하면 200이 되므로
    // 일치하는 시점도 있으므로 무조건 -1하면안됨.
    // 초과하는 시점을 찾고 마지막 항만 바꾸면 된다는 풀이.

    long long sum = 0;
    int i = 1;
    int ans = 0;
    while (true)
    {
        sum += i;
        ++i;
        ++ans;

        if (sum > s)
        {
            --ans;
            break;
        }
        else if (sum == s)
        {
            break;
        }
    }

    std::cout << ans;

    // int nn;
    // std::cin >> nn;
    return 0;
}