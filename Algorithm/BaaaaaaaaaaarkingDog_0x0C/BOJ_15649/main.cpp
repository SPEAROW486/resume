
#include <bits/stdc++.h>

// 상태 , 공간 할당이라는 키워드..
// 솔직히 코드가 짧아서 이 형태를 거의 외워서 푼거같으니까 문제 풀면서 체득 ㄱㄱ;

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

    for (int i = 1; i <= n; ++i)
    {
        if (!isused[i])
        {
            arr[k] = i;
            isused[i] = true;
            func(k + 1);
            isused[i] = false;
        }
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