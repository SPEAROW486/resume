
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int tc;

int main()
{
    // FASTIO;
    std::cin >> tc;
    while (tc--)
    {
        int n;
        std::cin >> n;

        std::string public1;
        std::string public2;
        std::string password;

        std::vector<std::string> key1(n), key2(n), cipher(n);
        std::unordered_map<std::string, int> key1_map;

        // Key1 입력
        for (int i = 0; i < n; ++i)
        {
            std::cin >> key1[i];
            key1_map[key1[i]] = i; // Key1의 단어와 해당 인덱스 저장
        }

        // Key2 입력
        for (int i = 0; i < n; ++i)
        {
            std::cin >> key2[i];
        }

        // Cipher 입력
        for (int i = 0; i < n; ++i)
        {
            std::cin >> cipher[i];
        }

        std::vector<std::string> origin(n);
        for (int i = 0; i < n; ++i)
        {
            int idx = key1_map[key2[i]];
            origin[idx] = cipher[i];
        }

        for (auto str : origin)
        {
            std::cout << str << " ";
        }
        std::cout << "\n";
    }

    int nn;
    std::cin >> nn;
    return 0;
}