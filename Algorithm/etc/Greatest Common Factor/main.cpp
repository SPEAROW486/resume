

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> GetCommonFactors(int _num)
{
    std::vector<int> v;

    for (int i = 0; i <= _num; ++i)
    {
        if (_num % i == 0)
        {
            v.push_back(i);
        }
    }
    return v;
}

int main()
{
    int num1 = 280;
    int num2 = 30;

    std::vector<int> v1 = GetCommonFactors(num1);
    std::vector<int> v2 = GetCommonFactors(num2);

    int gcf = 0;
    for (auto it = v1.begin(); it != v1.end(); ++it)
    {
        auto it2 = std::find(v2.begin(), v2.end(), *it);
        if (it2 != v2.end())
        {
            if (*it2 > gcf)
            {
                gcf = *it2;
            }
        }
    }

    std::cout << "Greatest Common Factor = " << gcf << std::endl;

    return 0;
}