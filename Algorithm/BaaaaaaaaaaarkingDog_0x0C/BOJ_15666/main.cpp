
#include <bits/stdc++.h>

constexpr int MAX = 9;

int n, m;
int sequence[MAX];
int arr[MAX];

void func(int k, int start)
{
    if (k == m)
    {
        for (int i = 0; i < m; ++i)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
        return;
    }

    // 재귀로 들어오면 다시 temp가 0이 되서 수열을 완성하는데에 문제가 없고
    // 1 7 9 9 에서
    // 1번째 1 9를 완성하고 그 다음 루프에서 2번째 1 9를 할때만 건너뛰게되는것..

    int temp = 0;
    for (int i = start; i < n; ++i)
    {
        if (temp == sequence[i])
        {
            continue;
        }

        arr[k] = sequence[i];
        temp = arr[k];
        func(k + 1, i);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        std::cin >> sequence[i];
    }
    std::sort(sequence, sequence + n);
    func(0, 0);

    return 0;
}