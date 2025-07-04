#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> d = {1, 3, 2, 5, 4};
    int budget = 9;

    sort(d.begin(), d.end());

    int answer = 0;
    for(auto dd : d) {
        budget -= dd;

        if(budget < 0) {
            break;
        }

        answer++;
    }

    std::cout << answer;
    return 0;
}