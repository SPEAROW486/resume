
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int main()
{
    FASTIO;

    int scenario = 0;
    while (true)
    {
        int n;
        std::cin >> n;

        if (n == 0)
        {
            break;
        }

        ++scenario;
        std::vector<std::string> names(n + 1);

        std::cin.ignore();
        for (int i = 0; i < n; ++i)
        {
            std::string s;
            std::getline(std::cin, s);

            names[i + 1] = s;
        }

        std::unordered_set<int> confiscated;
        for (int i = 0; i < 2 * n - 1; ++i)
        {
            int number;
            std::string iden;
            std::cin >> number >> iden;
            if (confiscated.find(number) != confiscated.end())
            {
                confiscated.erase(number);
            }
            else
            {
                confiscated.insert(number);
            }
        }

        if (confiscated.size() > 0)
        {
            // 1개를 못찾았다는 설정이니까
            std::cout << scenario << " " << names[*confiscated.begin()] << "\n";
        }
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}