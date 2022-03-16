#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

struct cmp {
    bool operator() (pair<int, int>& a, pair<int, int>& b) {
        return a.second > b.second;
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    int sum = 0;
    int total = 0;
    int comp_work = 0;
    sort(jobs.begin(), jobs.end());
    int size = jobs.size();
    while (comp_work != size || !pq.empty()) {
        while (comp_work < size && total >= jobs[comp_work][0]) {
            pq.push({ jobs[comp_work][0], jobs[comp_work][1] });
            comp_work++;
        }
        if (!pq.empty()) {
            int cur = pq.top().first;
            int time = pq.top().second;
            total += time;
            sum += total - cur;
            pq.pop();
            continue;
        }
        total++;
    }
    answer = sum / jobs.size();

    return answer;
}