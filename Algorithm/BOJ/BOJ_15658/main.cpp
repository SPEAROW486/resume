#include <bits/stdc++.h>
#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 15658

// 백트래킹으로 최댓값, 최솟값을 갱신할 변수
int max_result = INT_MIN;
int min_result = INT_MAX;

// 백트래킹 함수
void backtrack(std::vector<int> &nums, int plus, int minus, int multiply, int divide, int idx, int current_result)
{
    // 모든 수를 다 사용했다면 최댓값과 최솟값 갱신
    if (idx == nums.size())
    {
        if (current_result > max_result)
        {
            max_result = current_result;
        }
        if (current_result < min_result)
        {
            min_result = current_result;
        }
        return;
    }

    // 각각의 연산자에 대해 백트래킹 수행
    if (plus > 0)
    {
        backtrack(nums, plus - 1, minus, multiply, divide, idx + 1, current_result + nums[idx]);
    }
    if (minus > 0)
    {
        backtrack(nums, plus, minus - 1, multiply, divide, idx + 1, current_result - nums[idx]);
    }
    if (multiply > 0)
    {
        backtrack(nums, plus, minus, multiply - 1, divide, idx + 1, current_result * nums[idx]);
    }
    if (divide > 0)
    {
        // 음수를 양수로 나눌 때는 나눗셈 규칙에 따라 음수 처리
        if (current_result < 0)
        {
            backtrack(nums, plus, minus, multiply, divide - 1, idx + 1, -(-current_result / nums[idx]));
        }
        else
        {
            backtrack(nums, plus, minus, multiply, divide - 1, idx + 1, current_result / nums[idx]);
        }
    }
}

int main()
{
    FASTIO;

    int n;
    std::cin >> n;

    std::vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> nums[i];
    }

    int plus, minus, multiply, divide;
    std::cin >> plus >> minus >> multiply >> divide;

    // 백트래킹 시작
    backtrack(nums, plus, minus, multiply, divide, 1, nums[0]);

    // 결과 출력
    std::cout << max_result << "\n"
              << min_result << "\n";

    // int nn;
    // std::cin >> nn;

    return 0;
}
