#include <iostream>
#include <vector>
#include <queue>

int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> graph(n, std::vector<int>(m, 0));
    std::vector<std::vector<int>> dist(n, std::vector<int>(m, 0));
    std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));

    for(int i=0; i<n; i++)
    {
        std::string line;
        std::cin >> line;
        for(int j=0; j<m; j++)
            graph[i][j] = line[j] - '0';
    }

    std::queue<std::pair<int, int>> q;
    visited[0][0] = true;
    q.push({0, 0});
    dist[0][0] = 1;

    int dy[4] = {-1, 1, 0, 0};
    int dx[4] = {0, 0, -1, 1};

    while(!q.empty())
    {
        auto [cy, cx] = q.front();
        q.pop();

        for(int dir=0; dir<4; dir++)
        {
            auto ny = cy + dy[dir];
            auto nx = cx + dx[dir];

            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if(graph[ny][nx] == 1 && !visited[ny][nx])
            {
                visited[ny][nx] = true;
                dist[ny][nx] = dist[cy][cx] + 1;
                q.push({ny, nx});
            }
        }
    }

    std::cout << dist[n-1][m-1];

    return 0;
}