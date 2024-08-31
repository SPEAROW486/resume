#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 22333
// 1. 해시를 이용한 셋, 맵 문제
// 2. 문자열 파싱

// 접근 방법
// 1. n,m이 각각 20만이기에 O(NM) 으로 절대 불가능
// 2. 중복 입력 없음

int n, m;
std::unordered_set<std::string> keywords;

int main()
{
    FASTIO;
    std::cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        std::string tmp;
        std::cin >> tmp;
        keywords.insert(tmp);
    }

    for (int i = 0; i < m; ++i)
    {
        std::string tmp;
        std::cin >> tmp;

        std::stringstream ss(tmp);
        std::string w;

        while (std::getline(ss, w, ','))
        {
            keywords.erase(w);
        }
        std::cout << keywords.size() << "\n";
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}
