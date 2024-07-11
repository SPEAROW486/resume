
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int main()
{
    // FASTIO;

    std::vector<int> sequence = {1, 2, 3, 4};
    std::vector<bool> state(sequence.size());
    // std::fill(state.begin(), state.begin() + 3, true);
    std::fill(state.end() - 3, state.end(), true);

    // next -> state 오름차순
    // prev -> state 내림차순

    do
    {
        for (int i = 0; i < sequence.size(); ++i)
        {
            if (state[i])
            {
                std::cout << sequence[i] << " ";
            }
        }
        std::cout << "\n";
    } while (std::next_permutation(state.begin(), state.end()));

    int nn;
    std::cin >> nn;

    return 0;
}