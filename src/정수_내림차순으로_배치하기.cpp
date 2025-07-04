#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    std::vector<int> vec;

    while(n > 0) {
        vec.push_back(n % 10);
        n /= 10;
    }

    std::sort(vec.begin(), vec.end());

    long long answer = 0;
    long long num = 1;
    for(auto& v : vec) {
        answer += num * v;
        num *= 10;
    }

    return answer;
}

int main() {
    long long num = 118372;
    std::cout << solution(num) << "\n";
    return 0;
}
