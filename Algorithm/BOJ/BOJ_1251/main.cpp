
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

std::string s;

void solution(std::string word)
{
    std::string result(50, 'z');
    // 무조건 뒤집어야하는데 abdcefg 같은건 뒤집었을때 원본보다 사전순으로 앞설수있는케이스가 없어서 오답이였던것
    // 모든 경우의 수를 생각하는게 너무 힘든데..

    for (int i = 1; i < word.length() - 1; ++i)
    {
        for (int j = i + 1; j < word.length(); ++j)
        {
            std::string part1 = word.substr(0, i);
            std::string part2 = word.substr(i, j - i);
            std::string part3 = word.substr(j);

            std::reverse(part1.begin(), part1.end());
            std::reverse(part2.begin(), part2.end());
            std::reverse(part3.begin(), part3.end());

            std::string new_word = part1 + part2 + part3;
            if (new_word < result)
            {
                result = new_word;
            }
        }
    }
    std::cout << result << "\n";
}

int main()
{
    FASTIO;
    std::cin >> s;

    // 1. 쪼갠뒤 뒤집어서 합친게 사전순으로 가장 앞서는 단어가 될려면
    // 2. 쪼갤때 맨뒤글자가 사전순으로 빠른게 나와야 하므로? 앞에서부터 탐색하다가 짧은걸 찾으면 짜름.
    // 3. 그다음 뒤집고 합침.

    solution(s);

    // int nn;
    // std::cin >> nn;
    return 0;
}