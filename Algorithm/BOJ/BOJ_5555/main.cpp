
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

std::string s;
int n;
std::vector<std::string> v;

int main()
{
    // FASTIO;
    std::cin >> s;
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        std::string tmp;
        std::cin >> tmp;
        v.push_back(tmp);
    }

    // 맨앞부터 뒤까지 몇개들었는지 체크하고
    // 끝에서 처음으로 몇개들었는지 체크하면될듯한데

    int ans = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        const std::string tmp = v[i] + v[i].substr(0, s.size() - 1);

        int pos = 0;
        int idx = tmp.find(s, pos);
        if (idx != std::string::npos)
        {
            ++ans;
        }
        pos = idx;

        // 그냥 n-1개만큼 서브문자열을 뒤에 붙혀버리고 파인드하면되는거아님?
    }

    std::cout << ans << "\n";

    int nn;
    std::cin >> nn;
    return 0;
}