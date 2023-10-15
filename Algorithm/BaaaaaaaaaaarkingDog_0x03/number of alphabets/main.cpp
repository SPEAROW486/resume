#include <iostream>
#include <string>

int main()
{
    std::string word;
    std::cin >> word;

    int alphabets[26] = {0};

    for (int i = 0; i < 26; ++i)
    {
        for (int j = 0; j < word.length(); ++j)
        {
            if (word[j] - (97 + i) == 0)
            {
                ++alphabets[i];
            }
        }
    }

    for (int elem : alphabets)
    {
        std::cout << elem << " ";
    }

    return 0;
}