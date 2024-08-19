
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

std::vector<std::pair<int, int>> v;

std::pair<int, int> parse(std::string s)
{
    std::pair<int, int> p;
    p.first = (s[1] - '0') - 1;
    p.second = s[0] - 'A';
    return p;
}

int dx[8] = {2, 2, 1, 1, -1, -1, -2, -2};
int dy[8] = {1, -1, 2, -2, 2, -2, 1, -1};

bool visit[6][6];

int main()
{
    // FASTIO;
    for (int i = 0; i < 36; ++i)
    {
        std::string tmp;
        std::cin >> tmp;
        v.push_back(parse(tmp));
    }

    bool ans = true;
    memset(visit, false, sizeof(visit));
    visit[v[0].first][v[0].second] = true;
    // 역순으로 탐색하지 않고, 앞에서부터 다음 지점으로 이동할 수 있는지 확인
    for (int i = 1; i < 36; ++i)
    {
        int cx = v[i - 1].first;
        int cy = v[i - 1].second;

        int tx = v[i].first;
        int ty = v[i].second;

        bool found = false;
        for (int j = 0; j < 8; ++j)
        {
            int nx = cx + dx[j];
            int ny = cy + dy[j];

            if (nx < 0 || nx >= 6 || ny < 0 || ny >= 6)
            {
                continue;
            }

            // 나이트가 이동할 수 있는 지점이 다음 지점인지 확인
            if (nx == tx && ny == ty)
            {
                found = true;
                visit[tx][ty] = true; // 방문 처리
                break;
            }
        }

        if (!found)
        {
            // 이동할 수 없는 경우
            ans = false;
            break;
        }
    }

    // 마지막 지점에서 첫 지점으로 돌아갈 수 있는지 확인
    int cx = v[35].first;
    int cy = v[35].second;
    int tx = v[0].first;
    int ty = v[0].second;

    bool canReturn = false;
    for (int i = 0; i < 8; ++i)
    {
        int nx = cx + dx[i];
        int ny = cy + dy[i];
        if (nx == tx && ny == ty)
        {
            canReturn = true;
            break;
        }
    }

    // 모든 지점을 방문했는지 확인
    int cnt = 0;
    for (int i = 0; i < 6; ++i)
    {
        for (int j = 0; j < 6; ++j)
        {
            if (!visit[i][j])
                cnt++;
        }
    }

    if (ans && canReturn && cnt == 0)
    {
        std::cout << "Valid\n";
    }
    else
    {
        std::cout << "Invalid\n";
    }

    int nn;
    std::cin >> nn;
    return 0;
}