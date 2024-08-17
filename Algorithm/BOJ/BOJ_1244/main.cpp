
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n;
int student;
int gender;
int number;
std::vector<int> switches;

int main()
{
    FASTIO;

    std::cin >> n;
    switches.resize(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> switches[i];
    }

    std::cin >> student;
    for (int i = 0; i < student; ++i)
    {
        std::cin >> gender >> number;

        if (gender == 1)
        {
            for (int i = 1; i <= n; i++)
            {
                if (i % number == 0)
                {
                    switches[i] = !switches[i];
                }
            }
        }
        else
        {
            switches[number] = !switches[number];
            for (int i = 1; switches[number + i] == switches[number - i]; i++)
            {
                if (number + i > n || number - i < 1)
                {
                    break;
                }
                switches[number + i] = !switches[number + i];
                switches[number - i] = !switches[number - i];
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        std::cout << switches[i] << " ";
        if (i % 20 == 0)
        {
            std::cout << "\n";
        }
    }

    return 0;
}