
#include <bits/stdc++.h>

// p(1)이 성립한다
// p(n)이 성립한다면 p(n+1)도 성립한다.

// 이 아래 2줄을 항상 머릿속에..!
// n이 1일때 성립한다.
// n이 k일때 성립하면 n이 k+1도 성립함을 보인다.

// 하노이의탑에선 n번 원판은 옮기려면 1~ n-1번 원판까지 옮길수 있어야함.
// 옮길수 있다면 n번 원판도 옮길수 있다.

// 1번 원판을 언제나 옮길수 있음 따라서 2번 원판을 옮길수 있음
// n-1번 원판을 옮길수 있으면 n번 원판도 옮길수 있다고 가정 할수 있음.
// 그러므로 예시 입력인 3번 원판을 옮길수 있는지를 알려면 2번 원판, 1번 원판을 옮길 수 있어야함.
// 옮길 수 있다면 3번 원판도 옮길수 있음이 성립함.

// a->b로 n을 옮긴다.
void Hanoi(int a, int b, int n)
{
    // n이 1일땐 언제던지 옮길 수 있음.
    if (n == 1)
    {
        std::cout << a << " " << b << "\n";
        return;
    }

    // n이 k일때에 k-1을 옮길수 있으면 k도 옮길수 있으므로
    Hanoi(a, 6 - a - b, n - 1);
    std::cout << a << " " << b << "\n";
    Hanoi(6 - a - b, b, n - 1);
    return;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::cout << (1 << n) - 1 << "\n";
    Hanoi(1, 3, n);
    return 0;
}