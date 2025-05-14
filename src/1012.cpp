#include <iostream>
#include <vector>

int dy[4] = {-1, 1, 0, 0};  // 상하좌우
int dx[4] = {0, 0, -1, 1};

void dfs(int y, int x, int N, int M, std::vector<std::vector<int>>& graph, std::vector<std::vector<bool>>& visited) {
    visited[y][x] = true;

    for (int dir = 0; dir < 4; ++dir) {
        int ny = y + dy[dir];
        int nx = x + dx[dir];

        if (ny < 0 || ny >= N || nx < 0 || nx >= M)
            continue;

        if (graph[ny][nx] == 1 && !visited[ny][nx]) {
            dfs(ny, nx, N, M, graph, visited);
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;

    while (T--) {
        int M, N, K;
        std::cin >> M >> N >> K;

        std::vector<std::vector<int>> graph(N, std::vector<int>(M, 0));
        std::vector<std::vector<bool>> visited(N, std::vector<bool>(M, false));

        for (int i = 0; i < K; ++i) {
            int x, y;
            std::cin >> x >> y;
            graph[y][x] = 1;  // 주의: y = 세로, x = 가로
        }

        int count = 0;
        for (int y = 0; y < N; ++y) {
            for (int x = 0; x < M; ++x) {
                if (graph[y][x] == 1 && !visited[y][x]) {
                    dfs(y, x, N, M, graph, visited);
                    count++;
                }
            }
        }

        std::cout << count << '\n';
    }

    return 0;
}
