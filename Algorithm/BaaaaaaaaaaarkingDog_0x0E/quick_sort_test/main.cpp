
#include <bits/stdc++.h>

int n = 10;
int arr[1000001] = {15, 25, 22, 357, 16, 23, -53, 12, 46, 3};

// 피벗보다 작은값은 왼쪽, 크거나 같은 값은 오른쪽
void quick_sort(int start, int end)
{
    // base conditon
    if (end <= start + 1)
    {
        return;
    }

    int pivot = arr[start];
    int l = start + 1;
    int r = end - 1;
    while (true)
    {
        while (arr[l] <= pivot && l <= r)
        {
            ++l;
        }

        while (arr[r] > pivot && l <= r)
        {
            --r;
        }

        if (r < l)
        {
            break;
        }

        std::swap(arr[l], arr[r]);
    }
    std::swap(arr[start], arr[r]);
    quick_sort(start, r);
    quick_sort(r + 1, end);
}

int main()
{
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(NULL);

    quick_sort(0, n);
    for (int i = 0; i < n; ++i)
    {
        std::cout << arr[i] << " ";
    }

    int nn;
    std::cin >> nn;
    return 0;
}