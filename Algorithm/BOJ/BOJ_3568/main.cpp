
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int main()
{
    FASTIO;
    std::string input;
    std::getline(std::cin, input); // 전체 줄을 입력으로 받습니다.

    std::vector<std::string> tokens;
    std::string baseType;
    std::string temp = "";
    bool baseTypeFound = false;

    for (char ch : input)
    {
        if (ch == ' ' && !baseTypeFound)
        {
            baseType = temp;
            baseTypeFound = true;
            temp = "";
        }
        else if (ch == ',' || ch == ';')
        {
            tokens.push_back(temp);
            temp = "";
        }
        else
        {
            if (ch != ' ')
            {
                temp += ch;
            }
        }
    }

    for (std::string token : tokens)
    {
        std::string variableName = "";
        std::string variableType = baseType;

        for (int i = token.size() - 1; i >= 0; --i)
        {
            if (std::isalpha(token[i]))
            {
                variableName = token.substr(0, i + 1);
                break;
            }
            else if (token[i] == '[')
            {
                variableType += "[]";
            }
            else if (token[i] == ']')
            {
                continue;
            }
            else
            {
                variableType += token[i];
            }
        }

        std::cout << variableType << " " << variableName << ";" << std::endl;
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}
