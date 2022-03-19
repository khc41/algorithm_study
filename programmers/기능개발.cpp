#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int cnt = 0;
    while (cnt < progresses.size()) {
        for (int i = 0; i < progresses.size(); i++) {
            progresses[i] += speeds[i];
        }
        int comp = 0;
        for (int i = cnt; i < progresses.size(); i++) {
            if (progresses[i] >= 100) 
                comp++;
            else break;
        }
        if (comp != 0) {
            answer.push_back(comp);
            cnt += comp;
        }
    }
    return answer;
}

int main() {
    vector<int> p;
    p.push_back(93);
    p.push_back(30);
    p.push_back(55);

    vector<int> s;
    s.push_back(1);
    s.push_back(30);
    s.push_back(5);
    
    solution(p, s);
}