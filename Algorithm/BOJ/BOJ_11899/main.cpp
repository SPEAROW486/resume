
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

std::string s;

int solve()
{

    // 스택에 푸쉬하다가 쌍을 이루는게 나오면 기존 탑을 제거하는거, 새로 추가도 하지말고
    // 그렇게 하고 남은 스택에 사이즈가 정답일듯
    int ans = 0;
    std::stack<char> stack;
    for (int i = 0; i < s.size(); ++i)
    {
        // 스택의 탑과 현재 문자가 올바른 조합인지 확인
        if (!stack.empty() && stack.top() == '(' && s[i] == ')')
        {
            stack.pop();
        }
        else
        {
            stack.push(s[i]);
        }
    }

    return stack.size();
}

int main()
{
    FASTIO;
    std::cin >> s;

    std::cout << solve() << "\n";

    // int nn;
    // std::cin >> nn;
    return 0;
}