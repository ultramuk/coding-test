#include <iostream>
#include <vector>

int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, K;
    std::cin >> N >> K;

    std::vector<std::pair<int, int>> vec(N);
    std::vector<int> dp(K+1, 0);

    for(int i=0; i<N; i++)
    {
        std::cin >> vec[i].first >> vec[i].second;
    }

    for(int i=0; i<N; i++)
    {
        int w = vec.at(i).first;
        int v = vec.at(i).second;

        for(int weight = K;  weight >= w; --weight)
        {
            dp[weight] = std::max(dp[weight], dp[weight - w] + v);
        }
    }

    return 0;
}
