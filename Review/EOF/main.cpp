

#include <iostream>

int main()
{
    int number;
    std::string trash;
    while (!std::cin.eof()) // 터미널에선 컨트롤 Z가 EOF
    {
        std::cin >> number;

        if (std::cin.fail())
        {
            // Case 01 : 무한 루프
            // cin은 fail이 나면 이미 실패한거로 판단하여 더 이상 읽지 않는다.
            // std::cin >> trash; // 그러므로 이것도 읽지 않으므로 가리키는 위치가 그대로임
            // std::cin.clear();

            // Case 02 : 정상
            std::cin.clear();
            std::cin >> trash;
        }
        else
        {
            std::cout << number << std::endl;
        }
    }
    return 0;
}