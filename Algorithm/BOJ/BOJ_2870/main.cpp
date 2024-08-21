
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n;
std::vector<std::string> v;

std::vector<std::string> solve(const std::string &s)
{
    std::vector<std::string> ret;
    std::string buf;
    for (char ch : s)
    {
        if (isdigit(ch))
        {
            buf += ch;
        }
        else
        {
            if (!buf.empty())
            {
                buf.erase(0, buf.find_first_not_of('0'));
                if (buf.empty())
                {
                    buf = "0";
                }
                ret.push_back(buf);
                buf.clear();
            }
        }
    }

    if (!buf.empty())
    {
        buf.erase(0, buf.find_first_not_of('0'));
        if (buf.empty())
        {
            buf = "0";
        }
        ret.push_back(buf);
    }
    return ret;
}

int main()
{
    FASTIO;

    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        std::string tmp;
        std::cin >> tmp;
        v.push_back(tmp);
    }

    std::vector<std::string> ans;
    for (const std::string &str : v)
    {
        std::vector<std::string> sol = solve(str);
        ans.insert(ans.end(), sol.begin(), sol.end());
    }

    // 문자열을 사전순으로정렬하는게 아닌 문자로된 숫자기 때문에 사이즈가 작은애가 더 작다는거임.
    std::sort(ans.begin(), ans.end(), [](const std::string &a, const std::string &b)
              { return a.size() < b.size() || (a.size() == b.size() && a < b); });

    for (int i = 0; i < ans.size(); ++i)
    {
        std::cout << ans[i] << "\n";
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}
