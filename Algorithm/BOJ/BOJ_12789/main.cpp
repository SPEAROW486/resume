
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n;
std::vector<int> v;

bool solve()
{
    std::stack<int> s;
    std::vector<bool> ans(n + 1);
    int num = 1;
    for (const int order : v)
    {
        // 현재 차례면
        if (num == order)
        {
            ans[order] = true;
            ++num;
        }
        else
        {
            // if가 아니라 while로 대기열에 있는 애들이 순서대로 서있을 경우 다 털어줘야함.
            while (!s.empty() && s.top() == num)
            {
                ans[s.top()] = true;
                s.pop();
                ++num;
            }
            s.push(order);
        }
    }

    // 루프 다 돌고 스택이 비어있지 않을 수 있음.
    while (!s.empty())
    {
        if (s.top() == num)
        {
            ans[s.top()] = true;
            ++num;
        }
        s.pop();
    }

    bool result = true;
    for (int i = 1; i < ans.size(); ++i)
    {
        result &= ans[i];
    }
    return result;
}

int main()
{
    FASTIO;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        std::cin >> tmp;
        v.push_back(tmp);
    }

    if (solve())
    {
        std::cout << "Nice\n";
    }
    else
    {
        std::cout << "Sad\n";
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}