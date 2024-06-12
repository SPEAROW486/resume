
#include <bits/stdc++.h>

int n;

int main()
{

    std::cin >> n;

    // 팩토리얼을 계산해서 0을 세는거는 말이안되고
    // 0이 나오려면 10이 곱해져야 하는데
    // 5팩토리얼에는 2가 포함되서 무조건 10이 곱해지는 형태니까
    // 5가 몇개 들어있는지 체크를 하면되는데 25,125 같이 5의 배수인 경우에는 카운트를 그 배수만큼 올려줘야함.
    int cnt = 0;
    for (int i = 5; i <= n; i *= 5)
    {
        cnt += n / i;
    }

    std::cout << cnt;

    return 0;
}