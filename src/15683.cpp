#include <iostream>
#include <vector>
#include <algorithm>

const int dy[4] = {-1, 0, 1, 0};  // ↑ → ↓ ←
const int dx[4] = {0, 1, 0, -1};

// CCTV 종류별 감시 방향 조합
const std::vector<std::vector<std::vector<int>>> cctv_directions = {
    {},  // 0번 없음
    {{0}, {1}, {2}, {3}},                        // 1번
    {{0, 2}, {1, 3}},                            // 2번
    {{0, 1}, {1, 2}, {2, 3}, {3, 0}},            // 3번
    {{0, 1, 2}, {1, 2, 3}, {2, 3, 0}, {3, 0, 1}},// 4번
    {{0, 1, 2, 3}}                               // 5번
};

void watch(std::vector<std::vector<int>>& office, int y, int x, int dir) {
    int ny = y + dy[dir];
    int nx = x + dx[dir];
    int N = office.size();
    int M = office[0].size();

    while (0 <= ny && ny < N && 0 <= nx && nx < M) {
        if (office[ny][nx] == 6) break;
        if (office[ny][nx] == 0) office[ny][nx] = 7;  // 감시 표시
        ny += dy[dir];
        nx += dx[dir];
    }
}

int dfs(int idx, const std::vector<std::pair<int, int>>& cctvs, const std::vector<std::vector<int>>& map) {
    if (idx == cctvs.size()) {
        int blind = 0;
        for (const auto& row : map)
            for (int cell : row)
                if (cell == 0)
                    blind++;
        return blind;
    }

    int y = cctvs[idx].first;
    int x = cctvs[idx].second;
    int type = map[y][x];

    int result = 1e9;

    for (const auto& dirs : cctv_directions[type]) {
        std::vector<std::vector<int>> copy = map;
        for (int d : dirs)
            watch(copy, y, x, d);
        result = std::min(result, dfs(idx + 1, cctvs, copy));
    }

    return result;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> map(N, std::vector<int>(M));
    std::vector<std::pair<int, int>> cctvs;

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j) {
            std::cin >> map[i][j];
            if (1 <= map[i][j] && map[i][j] <= 5)
                cctvs.emplace_back(i, j);
        }

    int min_blind = dfs(0, cctvs, map);
    std::cout << min_blind << "\n";

    return 0;
}
