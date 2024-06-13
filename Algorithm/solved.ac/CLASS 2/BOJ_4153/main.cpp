
#include <bits/stdc++.h>

int a, b, c;

int main()
{

    while (true)
    {
        std::cin >> a >> b >> c;

        if (a == 0 && b == 0 && c == 0)
        {
            break;
        }

        int buf[3];
        buf[0] = a;
        buf[1] = b;
        buf[2] = c;

        std::sort(buf, buf + 3);

        bool result = buf[0] * buf[0] + buf[1] * buf[1] == buf[2] * buf[2];
        std::string s = result ? "right\n" : "wrong\n";
        std::cout << s;
    }

    return 0;
}