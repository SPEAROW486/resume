#include <iostream>
#include <queue>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::queue<int> q;

    int n = 0;
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        q.push(i + 1);
    }

    while (q.size() != 1)
    {
        q.pop();

        int f = q.front();
        q.pop();
        q.push(f);
    }

    std::cout << q.front();
}
