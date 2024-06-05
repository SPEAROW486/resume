
#include <bits/stdc++.h>

constexpr int MAX = 9;

int n, m;
int sequence[MAX];
int arr[MAX];
bool isused[MAX];

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

    for (int i = start; i < n; ++i)
    {
        arr[k] = sequence[i];
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