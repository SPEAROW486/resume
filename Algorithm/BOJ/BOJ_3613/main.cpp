
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// Java 스타일인지 확인
bool isJavaStyle(const std::string &s)
{
    if (s.empty() || s[0] == '_' || std::isupper(s[0]))
        return false; // 첫 글자가 '_'이거나 대문자면 Java 스타일이 아님
    for (char c : s)
    {
        if (c == '_')
            return false; // 언더스코어가 있으면 Java 스타일이 아님
    }
    return true;
}

// C++ 스타일인지 확인
bool isCppStyle(const std::string &s)
{
    if (s.empty() || s[0] == '_' || s.back() == '_')
        return false; // 시작이나 끝이 '_'이면 C++ 스타일이 아님
    if (std::isupper(s[0]))
        return false; // 첫 글자가 대문자면 C++ 스타일이 아님

    bool underscore = false;
    for (char c : s)
    {
        if (c == '_')
        {
            if (underscore)
                return false; // 연속된 '_'가 있으면 잘못된 형식
            underscore = true;
        }
        else
        {
            if (std::isupper(c))
                return false; // 대문자가 있으면 C++ 스타일이 아님
            underscore = false;
        }
    }
    return true;
}

// Java 스타일을 C++ 스타일로 변환
std::string toCppStyle(const std::string &s)
{
    std::string result;
    for (char c : s)
    {
        if (std::isupper(c))
        {
            result += '_';
            result += std::tolower(c);
        }
        else
        {
            result += c;
        }
    }
    return result;
}

// C++ 스타일을 Java 스타일로 변환
std::string toJavaStyle(const std::string &s)
{
    std::string result;
    bool nextUpper = false;
    for (char c : s)
    {
        if (c == '_')
        {
            nextUpper = true;
        }
        else if (nextUpper)
        {
            result += std::toupper(c);
            nextUpper = false;
        }
        else
        {
            result += c;
        }
    }
    return result;
}

int main()
{
    FASTIO;
    std::string s;
    std::cin >> s;

    // 문자열이 Java 스타일인지 C++ 스타일인지, 혹은 둘 다 아닌지 판별
    if (isJavaStyle(s))
    {
        std::cout << toCppStyle(s) << std::endl;
    }
    else if (isCppStyle(s))
    {
        std::cout << toJavaStyle(s) << std::endl;
    }
    else
    {
        std::cout << "Error!" << std::endl;
    }

    // int nn;
    // std::cin >> nn;

    return 0;
}
