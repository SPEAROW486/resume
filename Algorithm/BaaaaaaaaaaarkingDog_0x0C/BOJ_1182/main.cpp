
#include <bits/stdc++.h>

// 상태 공간 트리를 코드로 구현하는게 핵심인듯..?

int n, s, cnt;
int sequence[20];

void func(int cur, int total)
{
    if (cur == n)
    {
        if (total == s)
        {
            ++cnt;
        }
        return;
    }

    func(cur + 1, total);
    func(cur + 1, total + sequence[cur]);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> s;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> sequence[i];
    }

    func(0, 0);

    // 원소가 n개인 집합에서 부분집합의 개수는 2^n 인데 크기가 양수인 거만 체크해야하니까 공집합이면 -1해준다.
    if (s == 0)
    {
        --cnt;
    }
    std::cout << cnt;

    return 0;
}