//#include <vector>
//#include <queue>
//
//using namespace std;
//
//queue<int> solution(vector<int> progresses, vector<int> speeds) {
//    queue<int> tmp;
//    queue<int> answer;
//    int size = progresses.size();
//    for (int i = 0; i < size; i++) {
//        int j = 1;
//        while (progresses[i] + speeds[i] * j < 100) j++;
//        tmp.push(j);
//    }
//    // 7 3 9 -> 2 1
//    for (int i = 0; i < size; i++) {
//        while (tmp[i] >= tmp[i + 1]) {
//            tmp
//        }
//    }
//    return answer;
//}