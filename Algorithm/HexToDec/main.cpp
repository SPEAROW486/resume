

#include <iostream>

int main()
{
    int dec = 255;
    int hex = 0xff;

    std::cout << "Decimal " << dec << " to Hex " << std::hex << dec;
    std::cout << std::endl;
    std::cout << "HexDecimal " << hex << " to dec " << std::dec << hex;
    return 0;
}