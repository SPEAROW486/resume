

#include <iostream>

int GCFR(int num1, int num2)
{
    // Euclidean algorithm
    // a % b = r 이라고 하였을 때
    // a와 b의 최대 공약수를 (a,b)라고 하면
    // (a,b) == (b,r)이 성립한다.
    // (1071, 1029) == (1029, 42) == (42, 21) == (21, 0) = 21
    if (num2 == 0)
    {
        return num1;
    }
    else
    {
        return GCFR(num2, num1 % num2);
    }
}

int main()
{
    constexpr int NUM1 = 280;
    constexpr int NUM2 = 30;

    std::cout << "Greatest Common Factor = " << GCFR(NUM1, NUM2);
    return 0;
}