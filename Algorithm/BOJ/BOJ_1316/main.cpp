
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n;
std::vector<std::string> v;

bool solution(std::string word)
{
    // 일단 순회는 무조건 해야됨.
    std::vector<bool> use(26, false);

    for (int i = 0; i < word.length(); ++i)
    {
        // 같은 단어는 연속해서 나와야함.
        // 그렇다면 한번 나온 단어가 또 나왔을때 그 이전 단어랑 같아야 한다는 소리

        const int idx = word[i] - 'a';
        if (use[idx] && i > 0)
        {
            // 만약 사용한 단어인데 이전 단어랑 지금 단어랑 다르다면 ?
            if (word[i - 1] != word[i])
            {
                return false;
            }
        }
        else
        {
            use[idx] = true;
        }
    }

    return true;
}

int main()
{
    FASTIO;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        std::string s;
        std::cin >> s;
        v.push_back(s);
    }

    int ans = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        if (solution(v[i]))
        {
            ++ans;
        }
    }

    std::cout << ans;

    // int nn;
    // std::cin >> nn;
    return 0;
}