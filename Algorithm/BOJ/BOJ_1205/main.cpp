
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n;
std::vector<std::string> v;

int main()
{
    FASTIO;
    std::cin >> n;
    int length = 0;
    for (int i = 0; i < n; ++i)
    {
        std::string tmp;
        std::cin >> tmp;
        v.push_back(tmp);

        length = tmp.length();
    }

    // 최소 1자리는 남겨야 할테니까?
    // 루프안에서 정답을 못찾으면 입력 길이 그대로임.
    for (int i = 1; i < length; ++i)
    {
        std::unordered_set<std::string> set;
        for (int j = 0; j < v.size(); ++j)
        {
            std::string tmp = v[j].substr(v[j].length() - i, i);
            set.insert(tmp);
        }

        if (set.size() == n)
        {
            std::cout << i << "\n";
            return 0;
        }
    }

    std::cout << length << "\n";

    // int nn;
    // std::cin >> nn;
    return 0;
}