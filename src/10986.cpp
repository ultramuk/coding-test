#include <iostream>
#include <vector>

int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;

    std::vector<int> vec(N);
    for(auto& v : vec)
        std::cin >> v;

    std::vector<long long> count_mod(M, 0);  // 나머지별 등장 횟수
    long long prefix = 0;
    long long result = 0;

    count_mod[0] = 1;  // prefix % M == 0인 경우 고려

    for (int i = 0; i < N; i++) {
        prefix += vec[i];
        int mod = prefix % M;
        if (mod < 0) mod += M;  // 음수 나머지 보정
        result += count_mod[mod];
        count_mod[mod]++;
    }

    std::cout << result << "\n";

    return 0;
}
