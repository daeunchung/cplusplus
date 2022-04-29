#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector <string> v;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;

    for (int i = 0; i < cities.size(); i++) {
        string city = cities[i];
        transform(city.begin(), city.end(), city.begin(), ::tolower);   // 소문자로 변환

        if (cacheSize == 0) {
            answer += 5;
            continue;
        }
        auto itr = find(v.begin(), v.end(), city);
        if (itr != v.end()) {
            answer += 1;
            v.erase(itr);
        }
        else {
            if (v.size() == cacheSize) {
                v.erase(v.begin());
            }
            answer += 5;
        }
        v.push_back(city);
    }
    return answer;
}