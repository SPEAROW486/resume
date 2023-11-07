#include <iostream>
#include <stack>

// 스택은 제일 위의 데이터만 접근가능 하기 때문에
// 계산할때 스택의 사이즈를 이용한다던가, 페어를 이용해서 스택 맨위 데이터에 추가적인 정보를 저장하던가
// 실제 데이터는 다른 버퍼에 담아놓고, 스택을 이용해서 그 데이터를 조회한다던가 등의 생각을 해야 하는 듯

// 1. 더 이상 직사각형을 만들 수 없을 떄 까지 스택에 쌓는다. (현재 막대보다 이번 막대가 더 작을 경우) 그러므로 스택에는 오름차순으로 데이터가 쌓인다.
// 2. 현재 막대의 이전 구간부터 더 이상 직사각형을 만들지 못하는 구간사이에 몇개의 막대가 존재하는지 ?
// 3. 현재 막대의 높이 * 2번 결과를 answer와 비교해서 더 큰 값을 answer에 저장한다.

long long buf[100001] = {0};

void Solution(int n)
{
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> buf[i];
    }

    buf[0] = buf[n + 1] = 0;

    long long answer = 0;
    std::stack<int> s;
    for (int i = 1; i <= n + 1; ++i)
    {
        // 현재 막대랑 인풋이랑 비교해서 인풋이 더 작으면 더 이상 직사각형을 못만들고 같으면 기존꺼가 필요없어짐
        // 지금까지 스택(인덱스를 담아둠) 에 쌓아둔 막대들로 가장 큰 직사각형을 구해봐야함.
        while (!s.empty() && buf[s.top()] >= buf[i])
        {
            // 현재 막대를 포함해서 이번에 들어온 막대 사이에 몇개가 있는지 체크해서
            // 그 개수만큼 현재 막대에 곱해주면 직사각형의 넓이를 구할 수 있음.

            // 현재 막대의 인덱스 - s.top();
            // 이번 막대의 인덱스 - i
            int height = s.top();
            s.pop();

            // 스택이 비어있을수도 있음.
            int length = !s.empty() ? i - s.top() - 1 : i - 1;
            answer = std::max(answer, buf[height] * length);
        }
        s.push(i);
    }
    std::cout << answer << std::endl;
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    while (true)
    {
        int n = 0;
        std::cin >> n;
        if (n == 0)
        {
            break;
        }

        Solution(n);
    }
    return 0;
}
