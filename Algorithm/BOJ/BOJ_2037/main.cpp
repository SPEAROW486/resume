#include <bits/stdc++.h>
#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 2037

// 각 숫자 키패드에 해당하는 문자들
std::vector<std::string> keypad = {
    " ",    // 0번 키
    "",     // 1번 키 (사용하지 않음)
    "ABC",  // 2번 키
    "DEF",  // 3번 키
    "GHI",  // 4번 키
    "JKL",  // 5번 키
    "MNO",  // 6번 키
    "PQRS", // 7번 키
    "TUV",  // 8번 키
    "WXYZ"  // 9번 키
};

// 주어진 문자를 입력하기 위해 필요한 키와 입력 횟수를 반환
std::pair<int, int> getKeyAndPressCount(char c)
{
    for (int i = 0; i <= 9; ++i)
    {
        size_t pos = keypad[i].find(c);
        if (pos != std::string::npos)
        {
            return {i, static_cast<int>(pos + 1)}; // i번 키를 pos + 1번 눌러야 함
        }
    }
    return {-1, 0}; // 찾을 수 없는 경우는 발생하지 않음
}

int main()
{
    FASTIO;

    int pressTime, waitTime;
    std::cin >> pressTime >> waitTime; // 각 키를 누르는 시간과 같은 키를 반복할 때의 대기 시간 입력

    std::string message;
    std::cin.ignore();               // 이전 입력 버퍼를 비움
    std::getline(std::cin, message); // 전체 메시지 입력

    int totalTime = 0;
    int prevKey = -1; // 이전에 눌렀던 키의 번호

    for (char c : message)
    {
        if (c == ' ')
        {
            totalTime += pressTime; // 공백은 항상 0번 키를 1번 누르면 됨
            prevKey = 0;
        }
        else
        {
            std::pair<int, int> ret = getKeyAndPressCount(c);
            int key = ret.first;
            int presses = ret.second;
            totalTime += presses * pressTime; // 현재 문자를 입력하기 위한 시간 추가

            // 이전 키와 같은 키면 대기 시간 추가
            if (key == prevKey)
            {
                totalTime += waitTime;
            }
            prevKey = key; // 현재 키를 이전 키로 업데이트
        }
    }

    std::cout << totalTime << "\n"; // 결과 출력

    return 0;
}
