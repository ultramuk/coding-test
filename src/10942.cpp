#include <iostream>
#include <vector>

int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::cin >> N;

    std::vector<int> vec(N);
    for(auto& v : vec)
        std::cin >> v;

    bool dp[N+1][N+1] = {false};
    for (int i=0; i<N; i++) dp[i][i] = true;
    for (int i=0; i<N-1; i++) dp[i][i+1] = (vec[i] == vec[i+1]);
    for (int len=3; len<=N; len++) {
        for(int i=0; i+len-1<N; i++) {
            int j = i+len-1;
            dp[i][j] = (vec[i] == vec[j] && dp[i+1][j-1]);
        }
    }

    std::cin >> M;
    while (M--)
    {
        int S, E;
        std::cin >> S >> E;

        std::cout << static_cast<int>(dp[S-1][E-1]) << "\n";
    }

    return 0;
}