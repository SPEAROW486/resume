
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n;
int a, b;
int cal;

std::vector<int> toppings;
int main()
{
    FASTIO;

    // 1원당 가장 열량이 높은 피자
    // 그냥 브루트포스같은데?
    std::cin >> n;
    std::cin >> a >> b;
    std::cin >> cal;

    // 도우의 열량은 깔고가는거고
    // 이 토핑을 더하는게 좋을지 안더하는게 좋을지 해야함.

    int ans = cal / a;
    int current_cal = cal;
    int current_price = a;

    for (int i = 0; i < n; ++i)
    {
        int tmp;
        std::cin >> tmp;
        toppings.push_back(tmp);
    }

    std::sort(toppings.begin(), toppings.end(), std::greater<>());

    for (int i = 0; i < n; ++i)
    {
        // 출력이 소수점 이하를 버린다고 해서 int로 했더니 틀림
        // 값 자체는 소수점을 포함해서 더 크다면 업데이트를 해주고
        // 출력할때만 버리는것..
        double tmp = (current_cal + toppings[i]) / (current_price + b);
        if (tmp >= ans)
        {
            ans = tmp;
            current_cal += toppings[i];
            current_price += b;
        }
    }

    std::cout << ans << "\n";

    // int nn;
    // std::cin >> nn;
    return 0;
}