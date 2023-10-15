#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    int n = 0;
    std::cin >> n;

    std::vector<std::string> buf(n);
    for (int i = 0; i < n; ++i)
    {
        std::string a;
        std::string b;

        std::cin >> a >> b;

        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());

        std::string msg = a == b ? "Possible\n" : "Impossible\n";
        buf.push_back(msg);
    }

    for (const auto &elem : buf)
    {
        std::cout << elem;
    }

    return 0;
}
