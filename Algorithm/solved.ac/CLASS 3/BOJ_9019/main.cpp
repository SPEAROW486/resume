
#include <bits/stdc++.h>

constexpr int MAX = 10001;
int visit[MAX];

int d_op(int a)
{
    return (2 * a) % 10000;
}

int s_op(int a)
{
    return a == 0 ? 9999 : a - 1;
}

int l_op(int a)
{
    return (a * 10) % 10000 + a / 1000;
}

int r_op(int a)
{
    return (a / 10) + (a % 10) * 1000;
}

void BFS(int a, int b);
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int tc;
    std::cin >> tc;
    while (tc--)
    {
        int a, b;
        std::cin >> a >> b;

        BFS(a, b);
        std::fill(visit, visit + MAX, false);
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}

void BFS(int a, int b)
{
    std::queue<std::pair<int, std::string>> q;
    q.push({a, ""});
    visit[a] = true;

    while (!q.empty())
    {
        int num = q.front().first;
        std::string cmd = q.front().second;
        q.pop();

        if (num == b)
        {
            std::cout << cmd << "\n";
            return;
        }

        int d, s, l, r;

        d = d_op(num);
        if (!visit[d])
        {
            visit[d] = true;
            q.push({d, cmd + "D"});
        }

        s = s_op(num);
        if (!visit[s])
        {
            visit[s] = true;
            q.push({s, cmd + "S"});
        }

        l = l_op(num);
        if (!visit[l])
        {
            visit[l] = true;
            q.push({l, cmd + "L"});
        }

        r = r_op(num);
        if (!visit[r])
        {
            visit[r] = true;
            q.push({r, cmd + "R"});
        }
    }
}