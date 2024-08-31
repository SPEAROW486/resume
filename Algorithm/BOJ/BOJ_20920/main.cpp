#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 20920
// 정렬

// 1. 자주 나올수록 앞에 배치 (빈도수를 저장할 map을 하나 두고)
// 2. 길이가 길수록
// 3. 사전 순

int n, m;
std::vector<std::string> words;
std::unordered_map<std::string, int> counts;

bool compare(const std::string &lhs, const std::string &rhs)
{
    if (counts[lhs] != counts[rhs])
    {
        return counts[lhs] > counts[rhs];
    }
    else if (lhs.length() != rhs.length())
    {
        return lhs.length() > rhs.length();
    }
    else
    {
        return lhs < rhs;
    }
}

int main()
{
    FASTIO;
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        std::string tmp;
        std::cin >> tmp;

        if (tmp.length() < m)
        {
            continue;
        }

        ++counts[tmp];
        if (counts[tmp] == 1)
        {
            words.push_back(tmp);
        }
    }

    std::sort(words.begin(), words.end(), compare);
    for (int i = 0; i < words.size(); ++i)
    {
        std::cout << words[i] << "\n";
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}
