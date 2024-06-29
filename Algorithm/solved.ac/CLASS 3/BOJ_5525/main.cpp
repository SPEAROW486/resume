
#include <bits/stdc++.h>

constexpr int MAX = 1000001;

std::vector<int> Comupte_LPS(const std::string &pattern)
{
    int m = pattern.length();
    std::vector<int> lps(m);
    int i = 1;
    int len = 0;
    lps[0] = 0;

    while (i < m)
    {
        if (pattern[i] == pattern[len])
        {
            ++len;
            lps[i] = len;
            ++i;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                ++i;
            }
        }
    }

    return lps;
}

int KMP(const std::string &pattern, const std::string &text)
{
    int m = pattern.length();
    int n = text.length();

    std::vector<int> lps = Comupte_LPS(pattern);

    int i = 0; // 텍스트의 인덱스
    int j = 0; // 패턴의 인덱스
    int count = 0;

    while (i < n)
    {
        if (pattern[j] == text[i])
        {
            ++j;
            ++i;
        }

        if (j == m)
        {
            ++count;
            j = lps[j - 1];
        }
        else if (i < n && pattern[j] != text[i])
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                ++i;
            }
        }
    }

    return count;
}

int n, m;
std::string p;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    p += "I";
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        p += "OI";
    }

    std::cin >> m;
    std::string s;
    std::cin >> s;
    int count = KMP(p, s);

    std::cout << count;

    //  int nn;
    // std::cin >> nn;
    return 0;
}