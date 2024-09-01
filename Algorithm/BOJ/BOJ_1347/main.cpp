
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 1347

int main()
{
    FASTIO;

    int n;
    std::string commands;
    std::cin >> n >> commands;

    // 방향을 나타내기 위한 배열 (남, 서, 북, 동)
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1};

    // 현재 위치와 방향
    int dir = 0; // 처음 시작 방향은 남쪽
    int x = 0, y = 0;

    // 경로를 저장하기 위한 벡터
    std::vector<std::pair<int, int>> path;
    path.push_back({x, y});

    // 명령어 수행
    for (char command : commands)
    {
        if (command == 'L')
        {
            dir = (dir + +3) % 4; // 왼쪽 회전
        }
        else if (command == 'R')
        {
            dir = (dir + +1) % 4; // 오른쪽 회전
        }
        else if (command == 'F')
        {
            x += dx[dir];
            y += dy[dir];
            path.push_back({x, y});
        }
    }

    // 경로의 최소/최대 좌표를 찾아서 미로의 크기를 계산
    int min_x = 0, max_x = 0, min_y = 0, max_y = 0;
    for (auto p : path)
    {
        min_x = std::min(min_x, p.first);
        max_x = std::max(max_x, p.first);
        min_y = std::min(min_y, p.second);
        max_y = std::max(max_y, p.second);
    }

    // 미로의 크기
    int height = max_x - min_x + 1;
    int width = max_y - min_y + 1;

    // 미로를 초기화
    std::vector<std::vector<char>> maze(height, std::vector<char>(width, '#'));

    // 경로를 미로에 그리기
    for (auto p : path)
    {
        maze[p.first - min_x][p.second - min_y] = '.';
    }

    // 미로 출력
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            std::cout << maze[i][j];
        }
        std::cout << '\n';
    }

    int nn;
    std::cin >> nn;

    return 0;
}