#include <iostream>
#include <deque>
#include <queue>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::deque<std::pair<int, int>> deq;

    int n = 0;
    int l = 0;
    std::cin >> n >> l;

    // 덱에서 최솟값을 찾는 방법만 찾아보다가 해설을 봐버림 ㅅㅂ
    // 플래티넘은 뭔가 접근방법이 선뜻 생각안남.
    // 접근방법만 알면 할만한데..
    // 일단 덱에다가 값을 넣고 뺄때 비교하면서 넣고 빼야함.

    int temp = 0;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> temp;
        std::pair<int, int> p(i, temp);

        // Back이랑 이번에 들어온거랑 비교해서 백이 크면 필요없으니까 뽑아버린다
        while (!deq.empty() && deq.back().second >= p.second)
        {
            deq.pop_back();
        }

        // 그다음엔 구간 체크를 해서 필요없어진 구간을 다 뽑아버린다.
        while (!deq.empty() && i - deq.front().first >= l)
        {
            deq.pop_front();
        }

        deq.push_back(p);
        std::cout << deq.front().second << " ";
    }

    return 0;
}
