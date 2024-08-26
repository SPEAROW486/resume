
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int timeToSeconds(const std::string &time)
{
    int minutes = std::stoi(time.substr(0, 2));
    int seconds = std::stoi(time.substr(3, 2));
    return minutes * 60 + seconds;
}

std::string secondsToTime(int seconds)
{
    int minutes = seconds / 60;
    seconds %= 60;
    return (minutes < 10 ? "0" : "") + std::to_string(minutes) + ":" + (seconds < 10 ? "0" : "") + std::to_string(seconds);
}

int main()
{
    FASTIO;
    int n;
    std::cin >> n;

    int team1_score = 0, team2_score = 0;
    int team1_lead_time = 0, team2_lead_time = 0;
    int last_time = 0;
    int current_lead_team = 0;

    for (int i = 0; i < n; ++i)
    {
        int team;
        std::string time;
        std::cin >> team >> time;

        int current_time = timeToSeconds(time);

        if (current_lead_team == 1)
        {
            team1_lead_time += (current_time - last_time);
        }
        else if (current_lead_team == 2)
        {
            team2_lead_time += (current_time - last_time);
        }

        if (team == 1)
        {
            team1_score++;
        }
        else
        {
            team2_score++;
        }

        if (team1_score > team2_score)
        {
            current_lead_team = 1;
        }
        else if (team2_score > team1_score)
        {
            current_lead_team = 2;
        }
        else
        {
            current_lead_team = 0;
        }

        last_time = current_time;
    }

    if (current_lead_team == 1)
    {
        team1_lead_time += (2880 - last_time);
    }
    else if (current_lead_team == 2)
    {
        team2_lead_time += (2880 - last_time);
    }

    std::cout << secondsToTime(team1_lead_time) << std::endl;
    std::cout << secondsToTime(team2_lead_time) << std::endl;

    // int nn;
    // std::cin >> nn;

    return 0;
}
