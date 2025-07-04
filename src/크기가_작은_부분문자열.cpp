#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    string t = "3141592";
    string p = "271";

    int answer = 0;

    auto size = p.length();

    for(int i = 0; i < t.length() - size + 1; ++i) {
        cout << " " << t.substr(i, size) << "\n";

        if(stoi(t.substr(i, size)) <= stoi(p))
            answer++;
    }

    std::cout << answer << "\n";

    return 0;
}