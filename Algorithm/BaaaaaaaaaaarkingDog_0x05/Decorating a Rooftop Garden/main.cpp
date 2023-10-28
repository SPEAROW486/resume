#include <iostream>
#include <stack>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n = 0;
    std::cin >> n;

    // 1 <= n <= 80000 이 조건
    // 만약 n이 5고 타워가 5 4 3 2 1이라고 치면
    // 내려다볼수있는 타워의 총합은 10이므로 n(n-1) / 2 -> n^2이 되는데 80000^2이 되면 int의 범위를 넘어선다.
    // n 부터 1까지 차례대로 쭉 뭔가 할 수 있는거면 시간복잡도 부터 한번 생각해보자!!
    long long count = 0;
    std::stack<int> towers;
    for (int i = 0; i < n; ++i)
    {
        int input = 0;
        std::cin >> input;

        if (towers.empty())
        {
            towers.push(input);
            continue;
        }

        while (!towers.empty() && towers.top() <= input)
        {
            towers.pop();
        }
        count += towers.size();
        towers.push(input);
    }

    std::cout << count;
    return 0;
}
