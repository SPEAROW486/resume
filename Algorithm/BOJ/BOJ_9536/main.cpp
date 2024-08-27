
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int tc;

int main()
{
    FASTIO;
    std::cin >> tc;
    std::cin.ignore();
    while (tc--)
    {
        // 울음소리 문자열 스플릿
        std::string str;
        std::getline(std::cin, str);

        std::stringstream ss(str);
        std::string word;
        std::vector<std::string> words;

        std::unordered_map<std::string, bool> map;
        while (ss >> word)
        {
            words.push_back(word);
            map[word] = true;
        }

        std::string msg;
        while (std::getline(std::cin, msg))
        {
            if (msg == "what does the fox say?")
            {
                for (const auto &w : words)
                {
                    if (map[w])
                    {
                        std::cout << w << " ";
                    }
                }
                std::cout << "\n";
                break;
            }

            std::stringstream ss2(msg);
            std::string word2;
            std::vector<std::string> v;
            while (ss2 >> word2)
            {
                v.push_back(word2);
            }

            std::string sound = v[2];
            map[sound] = false;
        }
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}