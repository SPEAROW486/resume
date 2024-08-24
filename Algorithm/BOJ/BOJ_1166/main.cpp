
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n, l, w, h;

constexpr int MAX = 1e9;

int main()
{
    // FASTIO;

    std::cin >> n >> l >> w >> h;

    double left = 0;
    double right = MAX;

    double ans = 0.0;
    int cnt = 10000;
    while (cnt--)
    {
        double mid = (left + right) / 2;

        // mid사이즈의 정육면체 박스가 l*w*h 박스에 몇개까지 담길수있는지 최댓값을 하면되는데
        // l,w,h가 값이 매우 크기 때문에 이걸 다 곱해서 할순없고

        long long lcount = static_cast<long long>(l / mid);
        long long wcount = static_cast<long long>(w / mid);
        long long hcount = static_cast<long long>(h / mid);

        long long total = 1LL * lcount * wcount * hcount;
        if (total >= n)
        {
            ans = mid;
            left = mid;
        }
        else
        {
            right = mid;
        }
    }

    std::cout << std::fixed << std::setprecision(9) << ans << "\n";

    int nn;
    std::cin >> nn;
    return 0;
}