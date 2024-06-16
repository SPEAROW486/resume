
#include <bits/stdc++.h>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, c;
    std::cin >> n >> c;

    std::vector<int> nums;
    std::unordered_map<int, int> freq;
    std::unordered_map<int, int> occ;

    for (int i = 0; i < n; ++i)
    {
        int tmp;
        std::cin >> tmp;

        nums.push_back(tmp);
        freq[tmp]++;
        if (occ.find(tmp) == occ.end())
        {
            occ[tmp] = i;
        }
    }

    std::vector<std::pair<int, std::pair<int, int>>> v;
    for (const int &elem : nums)
    {
        v.push_back({elem, {freq[elem], occ[elem]}});
    }

    std::sort(v.begin(), v.end(), [](const std::pair<int, std::pair<int, int>> &lhs, const std::pair<int, std::pair<int, int>> &rhs)
              { 
                if(lhs.second.first != rhs.second.first)
                {
                    return lhs.second.first > rhs.second.first;    
                }
                return lhs.second.second < rhs.second.second; });

    for (const std::pair<int, std::pair<int, int>> &elem : v)
    {
        std::cout << elem.first << " ";
    }

    // int nn;
    // std::cin >> n;
    return 0;
}