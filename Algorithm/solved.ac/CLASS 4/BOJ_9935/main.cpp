
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

std::string s;
std::string c4;

std::string fire()
{
    char cmp = c4.back();
    std::stack<char> st;

    // 부분 문자열 찾아서 제거하면 시간초과됨.

    // 1. 스택에다가 문자를 푸쉬
    // 2. 푸쉬한 문자가 폭발 문자열의 끝 문자랑 비교
    // 3. 끝 문자가 같으면 폭발 문자열의 길이만큼 스택에서 팝해서 폭발 문자열이랑 비교
    // 4. 폭발 문자열이랑 다르다면 다시 스택에 푸쉬
    for (int i = 0; i < s.length(); ++i)
    {
        st.push(s[i]);

        if (cmp == s[i] && st.size() >= c4.length())
        {
            std::string tmp;
            tmp.resize(c4.length());
            for (int j = 0; j < c4.length(); ++j)
            {
                tmp[c4.length() - 1 - j] = st.top();
                st.pop();
            }

            if (tmp != c4)
            {
                for (int j = 0; j < tmp.length(); ++j)
                {
                    st.push(tmp[j]);
                }
            }
        }
    }

    if (st.size() > 0)
    {
        std::string ans;
        int i = 0;
        int size = st.size();
        ans.resize(size);
        while (!st.empty())
        {
            ans[size - i - 1] = st.top();
            st.pop();
            ++i;
        }
        return ans;
    }
    else
    {
        return "FRULA";
    }
}

int main()
{
    FASTIO;
    std::cin >> s >> c4;
    std::cout << fire();

    // int nn;
    // std::cin >> nn;

    return 0;
}