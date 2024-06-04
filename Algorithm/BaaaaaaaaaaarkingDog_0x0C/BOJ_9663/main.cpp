
#include <bits/stdc++.h>

// 상태 , 공간 할당이라는 키워드..
// 솔직히 코드가 짧아서 이 형태를 거의 외워서 푼거같으니까 문제 풀면서 체득 ㄱㄱ;

int n, cnt;
bool isused[16];
bool isused2[30];
bool isused3[30];

void func(int cur)
{
    if (cur == n)
    {
        ++cnt;
        return;
    }

    for (int i = 0; i < n; ++i)
    {
        if (!isused[i] && !isused2[cur + i] && !isused3[cur - i + n - 1])
        {
            isused[i] = true;
            isused2[cur + i] = true;
            isused3[cur - i + n - 1] = true;
            func(cur + 1);
            isused[i] = false;
            isused2[cur + i] = false;
            isused3[cur - i + n - 1] = false;
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    func(0);

    std::cout << cnt;

    return 0;
}