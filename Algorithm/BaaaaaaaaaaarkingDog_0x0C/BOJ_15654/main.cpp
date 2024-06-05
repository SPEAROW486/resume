
#include <bits/stdc++.h>

constexpr int MAX = 9;

int n, m;
int sequence[MAX];
int arr[MAX];
bool isused[MAX];

void func(int k)
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

    // 중복된 수열은 출력하면 안됨.
    // 근데 현재꺼 픽하고나면 다음꺼부턴 오름차순이여야하는데

    for (int i = 0; i < n; ++i)
    {
        if (isused[i])
        {
            continue;
        }
        isused[i] = true;
        arr[k] = sequence[i];
        func(k + 1);
        isused[i] = false;
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
    func(0);

    return 0;
}