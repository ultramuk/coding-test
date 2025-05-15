#include <iostream>
#include <queue>
#include <vector>

int COUNT = 0;
int MAX_SIZE = 0;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs(int y, int x, const int n, const int m,
        const std::vector<std::vector<int>>& graph, std::vector<std::vector<bool>>& visited)
{
    std::queue<std::pair<int, int> > q;
    visited[y][x] = true;
    q.push({y, x});

    int size = 0;
    while(!q.empty())
    {
        auto [cy, cx] = q.front();
        q.pop();
        size++;

        for(int dir=0; dir<4; dir++)
        {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];

            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if(graph[ny][nx] == 1 && !visited[ny][nx])
            {
                visited[ny][nx] = true;
                q.push({ny, nx});
            }
        }
    }


    MAX_SIZE = MAX_SIZE > size ? MAX_SIZE : size;
}

int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> graph(n, std::vector<int>(m, 0));
    std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            std::cin >> graph[i][j];
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(graph[i][j] == 1 && !visited[i][j])
            {
                bfs(i, j, n, m, graph, visited);
                COUNT++;
            }
        }
    }

    std::cout << COUNT << "\n" << MAX_SIZE;

    return 0;
}