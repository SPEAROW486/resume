
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

std::string document;
std::string word;

int main()
{
    FASTIO;
    std::getline(std::cin, document);
    std::getline(std::cin, word);

    int pos = 0;
    int ans = 0;
    while (true)
    {
        pos = document.find(word, pos);
        if (pos == std::string::npos)
        {
            break;
        }
        pos += word.length();

        ++ans;
    }

    std::cout << ans;

    // int nn;
    // std::cin >> nn;

    return 0;
}