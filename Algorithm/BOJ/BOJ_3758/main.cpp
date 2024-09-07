
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 3758
// 정렬, 구현

int main()
{
    FASTIO;
    int tc;
    std::cin >> tc;

    while (tc--)
    {
        int n; // 팀의 개수
        int k; // 문제의 개수
        int t; // 내 ID
        int m; // 로그 엔트리 (제출 시간)

        std::cin >> n >> k >> t >> m;

        // 각 팀의 ID만 저장
        std::vector<int> v(n + 1);

        // 각 팀이 제출한 기록
        std::vector<std::map<int, int>> logs_score(n + 1); // 문제 별 점수
        std::map<int, int> logs_total_score;               // 합산 점수
        std::map<int, int> logs_cnt;                       // 제출 횟수
        std::map<int, int> logs_time;                      // 마지막으로 제출한 시간

        for (int i = 0; i < m; ++i)
        {
            int id;     // 로그 ID
            int number; // 문제 번호
            int s;      // 획득한 점수

            std::cin >> id >> number >> s;

            v[id] = id;
            // 정렬에 필요한 정보는 해시맵에 저장
            if (logs_score[id].find(number) == logs_score[id].end())
            {
                logs_score[id].insert({number, s});
                logs_total_score[id] += s;
            }
            else
            {
                // 이미 제출한 기록이 있는 문제면 비교
                int prev_score = logs_score[id][number];
                if (prev_score < s)
                {
                    logs_score[id][number] = s;
                    logs_total_score[id] += s;
                    logs_total_score[id] -= prev_score;
                }
            }
            ++logs_cnt[id];
            logs_time[id] = i;
        }

        auto compare = [logs_total_score, logs_cnt, logs_time](int lhs, int rhs) mutable
        {
            if (logs_total_score[lhs] != logs_total_score[rhs])
            {
                // 점수가 다르면 더 높은 사람
                return logs_total_score[lhs] > logs_total_score[rhs];
            }
            else if (logs_cnt[lhs] != logs_cnt[rhs])
            {
                // 점수는 같은데 제출 횟수가 다르면 제출 횟수가 더 적은 사람
                return logs_cnt[lhs] < logs_cnt[rhs];
            }
            else
            {
                // 점수도 같고 제출 횟수도 같으면 제출한 시각이 더 이전인 사람
                return logs_time[lhs] < logs_time[rhs];
            }
        };

        std::sort(v.begin(), v.end(), compare);
        for (int i = 0; i < v.size(); ++i)
        {
            if (v[i] == t)
            {
                std::cout << i + 1 << "\n";
            }
        }
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}