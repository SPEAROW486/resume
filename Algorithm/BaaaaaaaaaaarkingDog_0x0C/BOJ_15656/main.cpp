
#include <bits/stdc++.h>

constexpr int MAX = 9;

int n, m;
int sequence[MAX];
int arr[MAX];
bool isused[MAX];

// 함수 시그니처에 변화를 줘야하는 케이스가 잘 생각이 안나네..
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

    for (int i = 0; i < n; ++i)
    {
        arr[k] = sequence[i];
        func(k + 1);
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