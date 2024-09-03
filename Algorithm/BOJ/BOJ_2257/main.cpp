
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 2257

int main()
{
    std::string formula;
    std::cin >> formula;

    std::map<char, int> atomic_weights;
    atomic_weights['C'] = 12;
    atomic_weights['H'] = 1;
    atomic_weights['O'] = 16;

    std::stack<int> s;
    int total_weight = 0;

    for (size_t i = 0; i < formula.length(); ++i)
    {
        char ch = formula[i];

        if (ch == '(')
        {
            s.push(-1);
        }
        else if (ch == ')')
        {
            int sum = 0;
            while (!s.empty() && s.top() != -1)
            {
                sum += s.top();
                s.pop();
            }
            s.pop();
            s.push(sum);
        }
        else if (isdigit(ch))
        {
            int num = ch - '0';
            int top = s.top();
            s.pop();
            s.push(top * num);
        }
        else
        {
            s.push(atomic_weights[ch]);
        }
    }

    while (!s.empty())
    {
        total_weight += s.top();
        s.pop();
    }

    std::cout << total_weight << std::endl;
    return 0;
}