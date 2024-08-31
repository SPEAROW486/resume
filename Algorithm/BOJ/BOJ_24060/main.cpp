#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 24060
// 1. 머지 소트 응용으로 보임

// 접근 방법
// 1. 머지 소트 구현
// 2. 몇 번째 정렬이 이루어지는지 찾아야함.

// 첫 제출에 시간초과
// 이후 벡터 사이즈를 미리 할당하고 인덱스 접근으로 수정 후 통과

int n, k, cnt;
int ans = -1;
std::vector<int> v;
std::vector<int> tmp;

void merge(int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int idx = 0;

    while (i <= mid && j <= right)
    {
        if (v[i] <= v[j])
        {
            tmp[idx++] = v[i++];
        }
        else
        {
            tmp[idx++] = v[j++];
        }
    }

    while (i <= mid)
    {
        tmp[idx++] = v[i++];
    }

    while (j <= right)
    {
        tmp[idx++] = v[j++];
    }

    for (int i = left; i <= right; ++i)
    {
        v[i] = tmp[i - left];
        ++cnt;

        if (cnt == k)
        {
            ans = v[i];
            return;
        }
    }
}

void merge_sort(int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        merge_sort(left, mid);
        merge_sort(mid + 1, right);
        merge(left, mid, right);
    }
}

int main()
{
    FASTIO;
    std::cin >> n >> k;

    v.resize(n);
    tmp.resize(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> v[i];
    }

    merge_sort(0, n - 1);
    std::cout << ans << "\n";

    // int nn;
    // std::cin >> nn;
    return 0;
}
