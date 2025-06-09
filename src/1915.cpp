#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> board(N, std::vector<int>(M));
    std::vector<std::vector<int>> dp(N, std::vector<int>(M));

    for(int i=0; i<N; i++) {
        std::string line;
        std::cin >> line;

        for(int j=0; j<M; j++)
            board[i][j] = line[j] - '0';
    }

    int max_len = 0;

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if (board[i][j] == 1) {
                if (i == 0 || j == 0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = std::min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;

                max_len = std::max(max_len, dp[i][j]);
            }
        }
    }

    std::cout << max_len * max_len;

    return 0;
}