#include <iostream>
#include <vector>

int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<std::vector<int>> dp(N, std::vector<int>(N));

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            std::cin >> dp[i][j];

    for(int k=0; k<N; k++)
    {
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                if(dp[i][k] && dp[k][j]) dp[i][j] = 1;
            }
        }
    }

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            std::cout << dp[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
