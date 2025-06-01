#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, K;
    std::cin >> N >> K;

    std::vector<std::pair<int, int> > vec(N);
    for(auto& v : vec)
        std::cin >> v.first >> v.second;

    std::vector<int> dp(K+1, 0);

    for(int i=0; i<N; i++)
    {
        int weight = vec[i].first;
        int value = vec[i].second;

        for(int w = K; w >= weight; --w)
        {
            dp[w] = std::max(dp[w], dp[w - weight] + value);
        }
    }

    std::cout << dp[K];

    return 0;
}
