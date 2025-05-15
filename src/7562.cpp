#include <iostream>
#include <vector>
#include <queue>

int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while(t--)
    {
        int n;
        std::cin >> n;

        std::vector<std::vector<int>> graph(n, std::vector<int>(n, 0));
        std::vector<std::vector<int>> dist(n, std::vector<int>(n, 0));
        std::vector<std::vector<bool>> visited(n, std::vector<bool>(n, false));

        int x, y, dst_x, dst_y;
        std::cin >> x >> y >> dst_x >> dst_y;

        std::queue<std::pair<int, int>> q;
        q.push({y, x});
        dist[y][x] = 1;
        visited[y][x] = true;

        int dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
        int dx[8] = {-2, -1, 1, 2, -2, -1, 1, 2};

        while(!q.empty())
        {
            auto [cy, cx] = q.front();
            q.pop();

            for(int dir=0; dir<8; dir++)
            {
                auto ny = cy + dy[dir];
                auto nx = cx + dx[dir];

                if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
                if(!visited[ny][nx])
                {
                    visited[ny][nx] = true;
                    dist[ny][nx] = dist[cy][cx] + 1;
                    q.push({ny, nx});
                }
            }
        }

        std::cout << dist[dst_y][dst_x] - 1 << "\n";
    }

    return 0;
}