#include <vector>
#include <queue>
using namespace std;
const int MAX_RATE = 100;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> days;
    int length = progresses.size();

    for (int i = 0; i < length; i++) {
        int remainigRate = MAX_RATE - progresses[i];
        int requiredDays = remainigRate / speeds[i];
        requiredDays += (remainigRate % speeds[i] != 0) ? 1 : 0;

        if (days.empty()) {
            days.push(requiredDays);
            continue;
        }

        // 이전 작업 남은 일수보다 적으면 같이 배포해야 함
        if (requiredDays <= days.front()) {
            days.push(requiredDays);
            continue;
        }

        int releaseNum = days.size();
        answer.push_back(releaseNum);
        
        while (!days.empty()) days.pop();
        days.push(requiredDays);
    }

    answer.push_back(days.size());
    return answer;
}