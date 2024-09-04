
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 2607
// 해시 맵?

bool is_match(const std::string &origin, const std::string &word)
{
    // 두 단어의 길이 차이가 2 이상이면 비슷할 수 없음
    if (abs((int)origin.length() - (int)word.length()) > 1)
    {
        return false;
    }

    // 알파벳 빈도를 저장할 두 해시맵
    std::unordered_map<char, int> origin_map, word_map;

    // 각 단어의 알파벳 빈도 계산
    for (char ch : origin)
    {
        ++origin_map[ch];
    }

    for (char ch : word)
    {
        ++word_map[ch];
    }

    // 차이 계산
    int diff_count = 0;
    for (auto &p : origin_map)
    {
        int origin_count = p.second;
        int word_count = word_map[p.first];
        diff_count += abs(origin_count - word_count);
    }

    // word_map에 있는데 origin_map에 없는 문자 처리
    for (auto &p : word_map)
    {
        if (origin_map.find(p.first) == origin_map.end())
        {
            diff_count += p.second;
        }
    }

    // 조건: 차이가 2 이하이면 비슷한 단어로 판단
    return diff_count <= 2;
}

int main()
{
    // FASTIO;

    int n;
    std::cin >> n;

    std::string origin;
    std::cin >> origin;

    int cnt = 0;
    for (int i = 1; i < n; ++i)
    {
        std::string word;
        std::cin >> word;

        if (is_match(origin, word))
        {
            ++cnt;
        }
    }

    std::cout << cnt << '\n';

    // int nn;
    // std::cin >> nn;
    return 0;
}