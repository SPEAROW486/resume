#include <bits/stdc++.h>
#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 15723

int main()
{
    FASTIO;

    int n;
    std::cin >> n; // 관계 개수 입력

    // 그래프 인접 행렬 초기화
    bool adj[26][26] = {false}; // 알파벳 개수(26)만큼의 배열

    for (int i = 0; i < n; ++i)
    {
        char a, b, c;
        std::cin >> a >> b >> c >> c; // a는 b이다 형식의 입력을 받음
        adj[a - 'a'][c - 'a'] = true;
    }

    // 플로이드-워셜 알고리즘을 이용한 모든 정점간의 관계 계산
    for (int k = 0; k < 26; ++k)
    {
        for (int i = 0; i < 26; ++i)
        {
            for (int j = 0; j < 26; ++j)
            {
                if (adj[i][k] && adj[k][j])
                {
                    adj[i][j] = true;
                }
            }
        }
    }

    int m;
    std::cin >> m; // 질문 개수 입력

    for (int i = 0; i < m; ++i)
    {
        char x, y, z;
        std::cin >> x >> y >> z >> z; // x는 y인가? 형식의 입력을 받음
        if (adj[x - 'a'][z - 'a'])
        {
            std::cout << "T\n"; // 관계가 성립하면 True
        }
        else
        {
            std::cout << "F\n"; // 관계가 성립하지 않으면 False
        }
    }

    return 0;
}
