#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> Q;
    int time = 1;
    for (int i = 0; i < progresses.size(); i++)
    {
        Q.push(progresses[i]);
    }
    int idx, num = 0;
    while (!Q.empty())
    {
        if (Q.front() + time * speeds[idx] >= 100)
        {
            num++;
            Q.pop();

        }
    }
    answer.push_back(num);

    return answer;
}