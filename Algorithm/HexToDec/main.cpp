

#include <iostream>
#include <algorithm>

std::string DecimalToHexString(const int dec)
{
    std::string hex;

    int num = dec;
    while (num != 0)
    {
        int mod = num % 16;

        if (mod >= 0 && mod <= 9)
        {
            hex += char(num % 16) + 48;
        }
        else if (mod >= 10 && mod <= 15)
        {
            hex += char(num % 16) + 55;
        }

        num /= 16;
    }
    std::reverse(hex.begin(), hex.end());
    return hex;
}

int HexStringToDecimal(const std::string &hex)
{
    int len = hex.size();

    int dec = 0;
    int base = 1;
    for (int i = len - 1; i >= 0; --i)
    {
        char ch = hex[i];

        if (ch >= '0' && ch <= '9')
        {
            dec += ((int)ch - 48) * base;
        }
        else if (ch >= 'A' && ch <= 'F')
        {
            dec += ((int)ch - 55) * base;
        }
        base *= 16;
    }
    return dec;
}

int main()
{
    int dec = 244;
    std::string hex = "FF";

    std::cout << dec << " To " << DecimalToHexString(dec) << std::endl;
    std::cout << hex << " To " << HexStringToDecimal(hex) << std::endl;
    return 0;
}