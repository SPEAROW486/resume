#include <iostream>

int Judgement(int num)
{
    return num == 0 ? 1 : 0;
}

void Solution(int a, int b, int c, int d)
{
    int yut = Judgement(a);
    yut += Judgement(b);
    yut += Judgement(c);
    yut += Judgement(d);

    switch (yut)
    {
    case 0:
        std::cout << "E" << std::endl;
        break;
    case 1:
        std::cout << "A" << std::endl;
        break;
    case 2:
        std::cout << "B" << std::endl;
        break;
    case 3:
        std::cout << "C" << std::endl;
        break;
    case 4:
        std::cout << "D" << std::endl;
        break;
    default:
        break;
    }

    return;
}

int main()
{
    int a, b, c, d;

    std::cin >> a >> b >> c >> d;
    Solution(a, b, c, d);

    std::cin >> a >> b >> c >> d;
    Solution(a, b, c, d);

    std::cin >> a >> b >> c >> d;
    Solution(a, b, c, d);

    return 0;
}