
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

    // 중복된 숫자 허용
    // 오름차순
    for (int i = 1; i <= n; ++i)
    {
        arr[k] = i;
        func(k + 1);
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