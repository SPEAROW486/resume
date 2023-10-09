#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n = 0;
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int a = 0, b = 0;
        std::cin >> a >> b;
        std::cout << a + b << "\n";
    }

    return 0;
}