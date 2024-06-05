
#include <bits/stdc++.h>

int n, m;
int arr[9];

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

    // 이 밑에가 좀 생각이 안나네..
    // 중복된 수열은 안됨.
    // 비내림차순 , A1 <= A2 여야한다는것.

    int start = 1;
    if (k != 0)
    {
        start = arr[k - 1];
    }

    for (int i = start; i <= n; ++i)
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