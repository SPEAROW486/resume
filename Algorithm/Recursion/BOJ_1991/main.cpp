
#include <bits/stdc++.h>

std::map<char, std::pair<char, char>> tree;

void PreOrder(char node)
{
    if (node == '.')
    {
        return;
    }
    std::cout << node;
    PreOrder(tree[node].first);
    PreOrder(tree[node].second);
}

void InOrder(char node)
{
    if (node == '.')
    {
        return;
    }
    InOrder(tree[node].first);
    std::cout << node;
    InOrder(tree[node].second);
}

void PostOrder(char node)
{
    if (node == '.')
    {
        return;
    }
    PostOrder(tree[node].first);
    PostOrder(tree[node].second);
    std::cout << node;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        char node, left, right;
        std::cin >> node >> left >> right;

        tree[node] = {left, right};
    }

    PreOrder('A');
    std::cout << "\n";

    InOrder('A');
    std::cout << "\n";

    PostOrder('A');
    std::cout << "\n";

    return 0;
}