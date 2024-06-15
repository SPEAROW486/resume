
#include <bits/stdc++.h>

int n = 10;
int arr[1000001] = {15, 25, 22, 357, 16, 23, -53, 12, 46, 3};
int tmp[1000001]; // merge 함수에서 리스트 2개를 합친 결과를 임시로 저장하고 있을 변수

void merge(int start, int end)
{
    // start ~ end-1까지 합치기
    int mid = (start + end) / 2;

    int lidx = start;
    int ridx = mid;
    for (int i = start; i < end; ++i)
    {
        if (lidx == mid)
        {
            tmp[i] = arr[ridx++];
        }
        else if (ridx == end)
        {
            tmp[i] = arr[lidx++];
        }
        else if (arr[lidx] <= arr[ridx])
        {
            tmp[i] = arr[lidx++];
        }
        else
        {
            tmp[i] = arr[ridx++];
        }
    }

    for (int i = start; i < end; ++i)
    {
        arr[i] = tmp[i];
    }
}

void merge_sort(int start, int end)
{
    // base conditon
    if (end == start + 1)
    {
        return;
    }
    int mid = (start + end) / 2;
    merge_sort(start, mid);
    merge_sort(mid, end);
    merge(start, end);
}

int main()
{
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(NULL);

    merge_sort(0, n);
    for (int i = 0; i < n; ++i)
    {
        std::cout << arr[i] << " ";
    }

    int nn;
    std::cin >> nn;
    return 0;
}