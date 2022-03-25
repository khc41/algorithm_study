#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int> pq;
    for (int i = 0; i < scoville.size(); i++) {
        pq.push(-scoville[i]);
    }
    while (!pq.empty()) {
        if (pq.size() < 2) {
            if (-pq.top() < K) answer = -1;
            break;
        }
        else {
            int first = -pq.top();
            pq.pop();
            int second = -pq.top();
            pq.pop();
            if (first >= K) break;

            int new_scoville = first + second * 2;
            pq.push(-new_scoville);
            answer++;
        }
    }

    return answer;
}