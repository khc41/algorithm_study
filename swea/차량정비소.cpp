#include <iostream>
#include <queue>
#include <vector>

struct customer {
public:
    int idx;
    int reception = 0;
    int repair = 0;
    int arrival_time;
    customer(int a, int b) {
        this->arrival_time = a;
        this->idx = b;
    }
};

struct desk {
public:
    int working_time;
    int remain_time = -1;
    customer cur = customer(0, 0);
    desk(int a) {
        this->working_time = a;
    }
};
using namespace std;

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int test_case;
    int T;
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case) {
        int N, M, K, A, B, in, answer = 0;
        cin >> N >> M >> K >> A >> B;
        vector<desk> reception;
        vector<desk> repair;
        queue<customer> cus;
        queue<customer> waiting;
        vector<customer> comp_cus;

        for (int i = 0; i < N; i++) {
            cin >> in;
            reception.push_back(desk(in));
        }
        for (int i = 0; i < M; i++) {
            cin >> in;
            repair.push_back(desk(in));
        }
        for (int i = 0; i < K; i++) {
            cin >> in;
            cus.push(customer(in, i+1));
        }

        int time = 0;
        int comp = 0;
        while (comp < K) {
            // waiting
            while (!waiting.empty()) {
                customer cur = waiting.front();
                int working = 0;
                for (int i = 0; i < M; i++) {
                    if (repair[i].remain_time == -1) {
                        repair[i].remain_time = repair[i].working_time;
                        cur.repair = i + 1;
                        repair[i].cur = cur;
                        waiting.pop();
                        break;
                    }
                    else working++;
                }
                if (working == M) break;
            }

            // cus
            while (!cus.empty()) {
                customer cur = cus.front();
                int working = 0;
                if (cur.arrival_time > time) break;
                for (int i = 0; i < N; i++) {
                    if (reception[i].remain_time == -1) {
                        cus.pop();
                        cur.reception = i + 1;
                        reception[i].cur = cur;
                        reception[i].remain_time = reception[i].working_time;
                        break;
                    }
                    else working++;
                }
                if (working == N) break;
            }

            // repair
            for (int i = 0; i < M; i++) {
                if (repair[i].remain_time > 0)
                    repair[i].remain_time--;
                if (repair[i].remain_time == 0) {
                    comp++;
                    repair[i].remain_time = -1;
                    comp_cus.push_back(repair[i].cur);
                }
            }

            // reception
            for (int i = 0; i < N; i++) {
                if (reception[i].remain_time > 0)
                    reception[i].remain_time--;
                if (reception[i].remain_time == 0) {
                    waiting.push(reception[i].cur);
                    reception[i].remain_time = -1;
                }
            }

            time++;
        }

        for (int i = 0; i < comp_cus.size(); i++) {
            if (comp_cus[i].reception == A && comp_cus[i].repair == B) {
                answer += comp_cus[i].idx;
            }
        }
        if(answer != 0)
            cout << "#" << test_case << " " << answer << endl;
        else 
            cout << "#" << test_case << " " << -1 << endl;
    }
    return 0;
}