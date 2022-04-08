// you can use includes, for example:
// #include <algorithm>
#include <stack>
#include <iostream>
using namespace std;

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(string& S) {
    // write your code in C++14 (g++ 6.2.0)
    stack<char> s;
    int answer = 1;
    for (int i = 0; i < S.size(); i++) {
        char word = S[i];
        if (word == '(' || word == '{' || word == '[') s.push(word);
        else if (word == ')') {
            if (s.top() != '(') {
                answer = 0; break;
            }
            else s.pop();
        }
        else if (word == '}') {
            if (s.top() != '{') {
                answer = 0; break;
            }
            else s.pop();
        }
        else if (word == ']') {
            if (s.top() != '[') {
                answer = 0; break;
            }
            else s.pop();
        }
    }
    if (!s.empty()) answer = 0;
    return answer;
}