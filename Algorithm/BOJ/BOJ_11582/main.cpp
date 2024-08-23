
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n, k;

void merge(std::vector<int> &vec, int left, int right)
{
    if ((right - left) > (n / k))
    {
        return;
    }

    int mid = (left + right) / 2;
    int lidx = left;
    int ridx = mid + 1;
    std::vector<int> sorted(right - left + 1);
    int kidx = 0;

    while (lidx <= mid && ridx <= right)
    {
        if (vec[lidx] <= vec[ridx])
        {
            sorted[kidx++] = vec[lidx++];
        }
        else
        {
            sorted[kidx++] = vec[ridx++];
        }
    }

    while (lidx <= mid)
    {
        sorted[kidx++] = vec[lidx++];
    }

    while (ridx <= right)
    {
        sorted[kidx++] = vec[ridx++];
    }

    // 정렬된 결과를 원본 벡터에 복사
    for (int i = 0; i < sorted.size(); ++i)
    {
        vec[left + i] = sorted[i];
    }
}

void mergesort(std::vector<int> &vec, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergesort(vec, left, mid);
        mergesort(vec, mid + 1, right);
        merge(vec, left, right);
    }
}

int main()
{
    FASTIO;
    std::cin >> n;

    std::vector<int> v;
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        std::cin >> tmp;
        v.push_back(tmp);
    }

    std::cin >> k;
    mergesort(v, 0, n - 1);

    for (int i = 0; i < v.size(); ++i)
    {
        std::cout << v[i] << " ";
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}