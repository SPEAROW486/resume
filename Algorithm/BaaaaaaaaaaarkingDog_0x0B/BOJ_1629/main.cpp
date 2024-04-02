
#include <bits/stdc++.h>

using ll = long long;

// k승을 구하면
// 2K승 , 2K+1 승을 구할수 있으니
// 모든 결과가 잘 계산될것이다 라고 추측할수 있다고 생각해야한다고함..

ll Solve(ll aa, ll bb, ll cc)
{
    // todo : base condition
    if (bb == 1)
    {
        // aa mod cc를 구함.
        // 여기서 결국 미지수 x를 구했음.
        // 그럼 x^2 도 x^2 + 1도 구할수있다는건데
        return aa % cc;
    }

    ll ans = Solve(aa, bb / 2, cc);
    ans = ans * ans % cc; // 나머지 정리에 의해 aa^bb mod cc와 같아짐.
    // ans를 구하면 ans^2도 구할수있다.
    // 지수가 짝수일경우 홀수일경우를 처리해야하겠네
    // 현재 지수의 절반을 구해서 곱하고 나머지를 구했으니 ans == x^b mod c랑 같음.
    if (bb % 2 == 0)
    {
        // Solve의 결과가 a^K 라고 했을때
        // ans = a^K * a^K % cc기 때문에
        // a^2K을 cc로 나눈 나머지값과 같다.
        return ans;
    }
    else
    {
        // 지수가 홀수면 A^2K * A를 해줘야하기 때문에
        // A에 해당하는 aa % cc를 곱해준다.
        return ans * aa % cc;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    ll a, b, c;
    std::cin >> a >> b >> c;

    std::cout << Solve(a, b, c);
    // A를 B번 곱한 수를 C로 나눈 나머지

    // A^B mod C를 구하는
    // (A mod c) ^B mod C랑 같다
    // 그러면 A mod C를 구해야함.
    // B가 1이 될때까지 구해나가고
    // 그 총합을 다시 mod c로 하면 답인듯?

    return 0;
}