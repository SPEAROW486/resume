
#include <bits/stdc++.h>

int n, m;
int arr[9];
bool isused[9];

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

    int start = 1;
    if (k != 0)
    {
        // 직전에 뽑은 수 보다 큰 수를 뽑으면 된다
        start = arr[k - 1] + 1;
    }
    for (int i = start; i <= n; ++i)
    {
        if (isused[i])
        {
            continue;
        }

        isused[i] = true;
        arr[k] = i;
        func(k + 1);
        isused[i] = false;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m;
    func(0);

    return 0;
}